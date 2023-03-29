#pragma once
#include <algorithm>
#include <unordered_map>
#include "InputSystem.h"

class PressedMouseButtonTrackSystem : InputSystem<PressedMouseButtonTrackNode, FRMouseButton>
{
public:
    PressedMouseButtonTrackSystem(std::unordered_map<std::string, PressedMouseButtonTrackNode> nodes)
        : nodes(std::move(nodes)) {}

    void addNode(std::string&& uuid, PressedMouseButtonTrackNode& node)
    {
        nodes.emplace(std::make_pair(uuid, node));
    }

    void process(FRMouseButton button)
    {
        std::ranges::for_each(nodes, [&](std::pair<const std::string, PressedMouseButtonTrackNode>& pair)
            {
                pair.second.setMouseButton(button);
            });
    }

    void removeNode(std::string key)
    {
        nodes.erase(key);
    }

private:
    std::unordered_map<std::string, PressedMouseButtonTrackNode> nodes;
};
