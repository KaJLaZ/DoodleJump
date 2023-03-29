#pragma once
#include <string>
#include "../nodes/BeyondBondaryMovingNode.h"

class BeyondBondaryMovingEntity
{
public:
    BeyondBondaryMovingEntity(std::string uuid, BeyondBondaryMovingNode beyondBondaryMovingNode)
        : uuid(std::move(uuid)),
          beyondBondaryMovingNode(beyondBondaryMovingNode){}

    std::string getUUID()
    {
        return uuid;
    }

    BeyondBondaryMovingNode& getPlatformGeneratorNode()
    {
        return beyondBondaryMovingNode;
    }

private:
    std::string uuid;
    BeyondBondaryMovingNode beyondBondaryMovingNode;
};
