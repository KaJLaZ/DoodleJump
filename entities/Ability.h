#pragma once

class Ability
{
public:
    Ability(std::string uuid, RenderNode renderNode, PlatformMovingNode platformMovingNode, AbilityNode abilityNode)
        : uuid(std::move(uuid)),
          renderNode(std::move(renderNode)),
          platformMovingNode(std::move(platformMovingNode)),
          abilityNode(std::move(abilityNode)){}

    std::string getUUID()
    {
        return uuid;
    }

    RenderNode& getRenderNode()
    {
        return renderNode;
    }

    RenderNode& getPlatformMovingNode()
    {
        return renderNode;
    }

    AbilityNode& getAbilityNode()
    {
        return abilityNode;
    }

private:
    std::string uuid;
    RenderNode renderNode;
    PlatformMovingNode platformMovingNode;
    AbilityNode abilityNode;
};
