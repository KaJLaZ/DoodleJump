#pragma once
#include <algorithm>
#include <unordered_map>

class ProjectileMovementSystem
{
public:
    ProjectileMovementSystem(std::unordered_map<std::string, ProjectileMovementNode> nodes)
        : nodes(std::move(nodes)){}

    void addNode(std::string&& uuid, ProjectileMovementNode& node)
    {
        nodes.emplace(std::make_pair(uuid, node));
    }
    
    void process()
    {
        std::ranges::for_each(nodes,[] (std::pair<const std::string, ProjectileMovementNode>& pair)
        {
            pair.second.shiftCoord(pair.second.getSpeed().getX(), pair.second.getSpeed().getY());
        });
    }

    void removeNode(std::string key)
    {
        nodes.erase(key);
    }
    
private:
    std::unordered_map<std::string, ProjectileMovementNode> nodes;
};
