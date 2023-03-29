#pragma once

#include <algorithm>
#include <unordered_map>
#include "System.h"
#include "../nodes/GravitationNode.h"

class GravitationSystem : System<GravitationNode>
{
public:
    GravitationSystem(std::unordered_map<std::string, GravitationNode> nodes)
        : nodes(std::move(nodes)){}

    void addNode(std::string&& uuid, GravitationNode& node)
    {
        nodes.emplace(std::make_pair(uuid, node));
    }
    
    void process()
    {
        std::ranges::for_each(nodes,[] (std::pair<const std::string, GravitationNode>& pair)
        {
            *pair.second.getGravitationSpeed() += 0.01;
            pair.second.shiftCoord(0, *pair.second.getGravitationSpeed());
        });
    }

    void removeNode(std::string key)
    {
        nodes.erase(key);
    }
    
private:
    std::unordered_map<std::string, GravitationNode> nodes;
};
