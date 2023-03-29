#pragma once
#include <algorithm>
#include <unordered_map>

#include "System.h"
#include "../utilities/Collider.h"

class ShootingEnemySystem : System<ShootingEnemyNode>
{
public:
    ShootingEnemySystem(std::unordered_map<std::string, ShootingEnemyNode> nodes)
        : nodes(std::move(nodes)){}

    void addNode(std::string&& uuid, ShootingEnemyNode& node)
    {
        nodes.emplace(std::make_pair(uuid, node));
    }

    void process()
    {
        std::ranges::for_each(nodes, [this](std::pair<const std::string, ShootingEnemyNode> pair)
            {
            for (Enemy &enemy : *pair.second.getEnemies())
            {
                auto projectileCoord = pair.second.getProjectileCoord();
                auto enemyCoord = enemy.getRenderNode().getCoord();
                auto projectileSize = pair.second.getProjectileSize();
                auto enemySize = enemy.getRenderNode().getSize();
                
                double a1x = projectileCoord->getX();
                double a2x = projectileCoord->getX() + projectileSize.getWidth();
                double a1y = projectileCoord->getY();
                double a2y = projectileCoord->getY() + projectileSize.getHeigth();
                double b1x = enemyCoord.getX();
                double b2x = enemyCoord.getX() + enemySize.getWidth();
                double b1y = enemyCoord.getY();
                double b2y = enemyCoord.getY() + enemySize.getHeigth();
                
                if(Collider::isCollide(a1x, a2x, a1y, a2y, b1x, b2x, b1y, b2y))
                {
                    pair.second.getRemovingUUID()->emplace(pair.second.getRemovingUUID()->begin(), enemy.getUUID());
                    pair.second.getRemovingUUID()->emplace(pair.second.getRemovingUUID()->begin(), pair.second.getProjectileUUID());
                }
            }
            });
    }

    void removeNode(std::string key)
    {
        nodes.erase(key);
    }

private:
    std::unordered_map<std::string, ShootingEnemyNode> nodes;
};
