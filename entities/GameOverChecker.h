#pragma once
#include <string>
#include "../nodes/GameOverCheckerNode.h"

class GameOverChecker
{
public:
    GameOverChecker(std::string uuid, GameOverCheckerNode gameOverCheckerNode)
        : uuid(std::move(uuid)),
          gameOverCheckerNode(std::move(gameOverCheckerNode)){}

    std::string getUUID()
    {
        return uuid;
    }

    GameOverCheckerNode getGameOverCheckerNode() const
    {
        return gameOverCheckerNode;
    }

private:
    std::string uuid;
    GameOverCheckerNode gameOverCheckerNode;
};
