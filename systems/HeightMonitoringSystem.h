#pragma once
#include <algorithm>
#include <unordered_map>
#include "../systems/System.h"
#include "PlatformMovingSystem.h"
#include "../nodes/HeightMonitoringNode.h"

class HeightMonitoringSystem : System<HeightMonitoringNode>
{
public:
    HeightMonitoringSystem(std::shared_ptr<PlatformMovingSystem> platformMovingSystem,
        std::shared_ptr<EnemyMovingSystem> enemyMovingSystem,
        std::unordered_map<std::string, HeightMonitoringNode> nodes)
        : platformMovingSystem(std::move(platformMovingSystem)),
          enemyMovingSystem(std::move(enemyMovingSystem)),
          nodes(std::move(nodes)){}

    void addNode(std::string&& uuid, HeightMonitoringNode& node)
    {
        nodes.emplace(std::make_pair(uuid, node));
    }

    void process()
    {
        std::ranges::for_each(nodes, [this](std::pair<const std::string, HeightMonitoringNode> pair)
            {
            if(pair.second.getCoord().getY() < pair.second.getMaxHeight())
            {
                *pair.second.getScore() = *pair.second.getScore() + 0.02;
                pair.second.setCoord(pair.second.getCoord().getX(), pair.second.getMaxHeight());
                platformMovingSystem->process();
                enemyMovingSystem->process();
            }
            
            if(pair.second.getCoord().getY() > pair.second.getScreenResolution().height)
            {
                *pair.second.IsGameOver() = true;
            }
            });
    }

    void removeNode(std::string key)
    {
        nodes.erase(key);
    }

private:
    std::shared_ptr<PlatformMovingSystem> platformMovingSystem;
    std::shared_ptr<EnemyMovingSystem> enemyMovingSystem;
    std::unordered_map<std::string, HeightMonitoringNode> nodes;
};

