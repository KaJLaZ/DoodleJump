#pragma once
#include <string>

#include "../nodes/JumpNode.h"
#include "../nodes/PlatformMovingNode.h"

class Platform
{
public:
    Platform(std::string uuid, RenderNode renderNode, PlatformMovingNode platformMovingNode, JumpNode jumpNode)
        : uuid(std::move(uuid)),
          renderNode(std::move(renderNode)),
          platformMovingNode(std::move(platformMovingNode)),
          jumpNode(std::move(jumpNode)){}

    std::string getUUID()
    {
        return uuid;
    }

    RenderNode& getRenderNode()
    {
        return renderNode;
    }

    JumpNode& getJumpNode()
    {
        return jumpNode;
    }

private:
    std::string uuid;
    RenderNode renderNode;
    PlatformMovingNode platformMovingNode;
    JumpNode jumpNode;
};
