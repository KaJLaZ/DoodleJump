#pragma once
#include <algorithm>
#include <unordered_map>
#include <utility>
#include "EnemyMovingSystem.h"
#include "JumpOnEnemySystem.h"
#include "RenderSystem.h"
#include "../components/Size.h"
#include "../entities/Platform.h"
#include "../fabrics/SharedComponentsFabric.h"
#include "../utilities/RandomValueGenerator.h"
#include "../utilities/UUID.h"

class EnemyGeneratorSystem : InputSystem<EnemyGeneratorNode, Coord>
{
public:
    EnemyGeneratorSystem(std::shared_ptr<RenderSystem> renderSystem, std::shared_ptr<EnemyMovingSystem> enemyMovingSystem,
        std::shared_ptr<JumpOnEnemySystem> jumpOnEnemySystem,  std::unordered_map<std::string, EnemyGeneratorNode> nodes)
        : renderSystem(std::move(renderSystem)),
        enemyMovingSystem(std::move(enemyMovingSystem)),
        jumpOnEnemySystem(jumpOnEnemySystem),
        nodes(std::move(nodes)){}

    void addNode(std::string&& uuid, EnemyGeneratorNode& node)
    {
        nodes.emplace(std::make_pair(uuid, node));
    }

    void process(Coord platformCoord)
    {
        std::ranges::for_each(nodes, [this, &platformCoord](std::pair<const std::string, EnemyGeneratorNode> pair)
            {
                if( pair.second.getRandomValueGenerator()->generateRandomInt() / pair.second.getProbability() < 1)
                {
                    auto enemySize = pair.second.getEnemySize();
                    auto enemyCoord = std::make_shared<Coord>(Coord(platformCoord.getX(), platformCoord.getY() - enemySize.getHeigth()));

                    auto enemyUUID = UUID::generate();
                    RenderNode renderNode = NodesFabric::makeRenderNode(pair.second.getSprite(),
                        enemyCoord, enemySize);
                    EnemyMovingNode enemyMovingNode = NodesFabric::makeEnemyMovingNode(pair.second.getGravitationSpeed(),
                        pair.second.getScreenResolution(), enemyCoord, pair.second.getRemovingUUID(), enemyUUID);
                    JumpOnEnemyNode jumpOnEnemyNode(NodesFabric::makeJumpOnEnemyNode(pair.second.getDoodleCoord(), enemyCoord,
                        pair.second.getGravitationSpeed(), pair.second.getDoodleSize(), enemySize, pair.second.IsGameOver(),
                        pair.second.getRemovingUUID(), enemyUUID));
                    
                    renderSystem->addNode(enemyUUID.c_str(), renderNode);
                    enemyMovingSystem->addNode(enemyUUID.c_str(), enemyMovingNode);
                    jumpOnEnemySystem->addNode(enemyUUID.c_str(), jumpOnEnemyNode);
                    
                    pair.second.getEnemies()->emplace(pair.second.getEnemies()->begin(), enemyUUID.c_str(), renderNode, enemyMovingNode, jumpOnEnemyNode);
                }
            });
    }

    void removeNode(std::string key)
    {
        nodes.erase(key);
    }

private:
    std::shared_ptr<RenderSystem> renderSystem;
    std::shared_ptr<EnemyMovingSystem> enemyMovingSystem;
    std::shared_ptr<JumpOnEnemySystem> jumpOnEnemySystem;
    std::unordered_map<std::string, EnemyGeneratorNode> nodes;
};
