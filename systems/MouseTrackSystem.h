#pragma once

#include "InputSystem.h"
#include "../nodes/MouseTrackNode.h"
#include <unordered_map>
#include <algorithm>

class MouseTrackSystem : InputSystem<MouseTrackNode, Coord>
{
public:
    MouseTrackSystem(std::unordered_map<std::string, MouseTrackNode> nodes)
        : nodes(std::move(nodes)) {}

    void addNode(std::string&& uuid, MouseTrackNode& node)
    {
        nodes.emplace(std::make_pair(uuid, node));
    }

    void process(Coord coord)
    {
        std::ranges::for_each(nodes, [&](std::pair<const std::string, MouseTrackNode>& pair)
            {
                pair.second.setMouseCoord(coord.getX(), coord.getY());
            });
    }

    void removeNode(std::string key)
    {
        nodes.erase(key);
    }

private:
    std::unordered_map<std::string, MouseTrackNode> nodes;
};
