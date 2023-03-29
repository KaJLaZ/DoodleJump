#pragma once
#include <algorithm>
#include <memory>
#include <memory>
#include <unordered_map>
#include "ProjectileMovementSystem.h"
#include "RenderSystem.h"
#include "ShootingEnemySystem.h"
#include "System.h"
#include "../utilities/UUID.h"

class ProjectileGeneratorSystem : System<ProjectileGeneratorNode>
{
public:
    ProjectileGeneratorSystem(std::shared_ptr<RenderSystem> renderSystem,
        std::shared_ptr<ProjectileMovementSystem> projectileMovementSystem,
        std::shared_ptr<ShootingEnemySystem> shootingEnemySystem,
        std::unordered_map<std::string, ProjectileGeneratorNode> nodes)
        : renderSystem(std::move(renderSystem)),
          projectileMovementSystem(std::move(projectileMovementSystem)),
          shootingEnemySystem(std::move(shootingEnemySystem)),
          nodes(std::move(nodes)){}

    void addNode(std::string&& uuid, ProjectileGeneratorNode& node)
    {
        nodes.emplace(std::make_pair(uuid, node));
    }
    
    void process()
    {
        std::ranges::for_each(nodes,[this] (std::pair<const std::string, ProjectileGeneratorNode>& pair)
        {
            switch(pair.second.getPressedMouseButton())
            {
            case FRMouseButton::LEFT:
                
                double difX = pair.second.getMouseCoord().getX() - (pair.second.getDoodleCoord().getX() + pair.second.getDoodleSize().getWidth() / 2.0);
                double difY = pair.second.getMouseCoord().getY() - pair.second.getDoodleCoord().getY();

                double absSum = fabs(difX) + fabs(difY);
            
                double propX = difX / absSum;
                double propY = difY / absSum;
                
                auto projectileCoord = std::make_shared<Coord>(Coord(
                    pair.second.getDoodleCoord().getX() + pair.second.getDoodleSize().getWidth() / 2.0,
                    pair.second.getDoodleCoord().getY() - pair.second.getSize().getHeigth()));
                RenderNode renderNode(NodesFabric::makeRenderNode(pair.second.getSprite(), projectileCoord, pair.second.getSize()));
                auto projectileSpeed =  std::make_shared<Speed>(Speed(pair.second.getMoveDistance() * propX, pair.second.getMoveDistance() * propY));
                ProjectileMovementNode projectileMovementNode(projectileCoord, projectileSpeed);
                
                auto projectileUUID = UUID::generate();
                ShootingEnemyNode enemyNode = NodesFabric::makeShootingEnemyNode(projectileCoord, pair.second.getSize(), pair.second.getEnemies(), pair.second.getRemovingUUID(), projectileUUID);
                renderSystem->addNode(projectileUUID.c_str(), renderNode);
                projectileMovementSystem->addNode(projectileUUID.c_str(), projectileMovementNode);
                shootingEnemySystem->addNode(projectileUUID.c_str(), enemyNode);
                break;
            }
        });
    }

    void removeNode(std::string key)
    {
        nodes.erase(key);
    }
    
private:
    std::shared_ptr<RenderSystem> renderSystem;
    std::shared_ptr<ProjectileMovementSystem> projectileMovementSystem;
    std::shared_ptr<ShootingEnemySystem> shootingEnemySystem;
    std::unordered_map<std::string, ProjectileGeneratorNode> nodes;
};
