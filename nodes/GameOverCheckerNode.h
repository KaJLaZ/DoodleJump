#pragma once
#include <memory>


class GameOverCheckerNode
{
public:
    GameOverCheckerNode(std::shared_ptr<bool> isGameOver) : isGameOver(std::move(isGameOver)) {}

    std::shared_ptr<bool> IsGameOver()
    {
        return isGameOver;
    }

    void setGameOver(bool state)
    {
        *isGameOver = state;
    }

private:
    std::shared_ptr<bool> isGameOver;
};
