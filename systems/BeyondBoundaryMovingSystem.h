#pragma once

#include <algorithm>
#include <unordered_map>
#include "System.h"

class BeyondBoundaryMovingSystem : System<BeyondBondaryMovingNode>
{
public:
    BeyondBoundaryMovingSystem(std::unordered_map<std::string, BeyondBondaryMovingNode> nodes)
        : nodes(std::move(nodes)){}

    void addNode(std::string&& uuid, BeyondBondaryMovingNode& node)
    {
        nodes.emplace(std::make_pair(uuid, node));
    }
    
    void process()
    {
        std::ranges::for_each(nodes,[] (std::pair<const std::string, BeyondBondaryMovingNode>& pair)
        {
            auto doodleCoord = pair.second.getDoodleCoord();
            if (doodleCoord.getX() > pair.second.getScreenResolution().width)
            {
                pair.second.setDoodleCoord(0, doodleCoord.getY());
            }
            if (doodleCoord.getX() < pair.second.getSize().getWidth() * -1)
            {
                auto rightBorderDoodleXCoord = pair.second.getScreenResolution().width - pair.second.getSize().getWidth();
                pair.second.setDoodleCoord(rightBorderDoodleXCoord, doodleCoord.getY());
            }
        });
    }

    void removeNode(std::string key)
    {
        nodes.erase(key);
    }
    
private:
    std::unordered_map<std::string, BeyondBondaryMovingNode> nodes;
};
