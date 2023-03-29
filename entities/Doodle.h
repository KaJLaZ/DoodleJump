#pragma once
#include <string>

class Doodle
{
public:
    Doodle(std::string uuid, RenderNode renderNode, ConstantXMoveNode constantXMoveNode, GravitationNode gravitationNode,
        HeightMonitoringNode heightMonitoringNode)
        : uuid(std::move(uuid)),
          renderNode(std::move(renderNode)),
          constantXMoveNode(std::move(constantXMoveNode)),
          gravitationNode(std::move(gravitationNode)),
          heightMonitoringNode(std::move(heightMonitoringNode)){}

    std::string getUUID()
    {
        return uuid;
    }

    RenderNode& getRenderNode()
    {
        return renderNode;
    }

    ConstantXMoveNode& getConstantXMoveNode()
    {
        return constantXMoveNode;
    }

    GravitationNode& getGravitationNode()
    {
        return gravitationNode;
    }

    HeightMonitoringNode& getHeightMonitoringNode()
    {
        return heightMonitoringNode;
    }


private:
    std::string uuid;
    RenderNode renderNode;
    ConstantXMoveNode constantXMoveNode;
    GravitationNode gravitationNode;
    HeightMonitoringNode heightMonitoringNode;
};
