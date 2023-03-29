#pragma once
#include <memory>
#include "../components/Coord.h"

class JumpNode
{
public:
    JumpNode(std::shared_ptr<Coord> doodleCoord, std::shared_ptr<Coord> platformCoord,
        std::shared_ptr<double> gravitationSpeed, Size doodleSize, Size platformSize, const double jumpForce,
        std::shared_ptr<double> score, std::shared_ptr<double> lastScore, std::shared_ptr<int> jumpCounter)
        : doodleCoord(std::move(doodleCoord)),
          platformCoord(std::move(platformCoord)),
          gravitationSpeed(std::move(gravitationSpeed)),
          doodleSize(doodleSize),
          platformSize(platformSize),
          jumpForce(jumpForce),
          score(std::move(score)),
          lastScore(std::move(lastScore)),
          jumpCounter(std::move(jumpCounter)){}

    std::shared_ptr<Coord> getDoodleCoord()
    {
        return doodleCoord;
    }

    std::shared_ptr<Coord> getPlatformCoord()
    {
        return platformCoord;
    }

    std::shared_ptr<double> getGravitationSpeed()
    {
        return gravitationSpeed;
    }

    Size getDoodleSize()
    {
        return doodleSize;
    }

    Size getPlatformSize()
    {
        return platformSize;
    }

    double getJumpForce()
    {
        return jumpForce;
    }

    std::shared_ptr<double> getScore()
    {
        return score;
    }

    std::shared_ptr<double> getLastScore()
    {
        return lastScore;
    }

    std::shared_ptr<int> getJumpCounter()
    {
        return jumpCounter;
    }

private:
    std::shared_ptr<Coord> doodleCoord;
    std::shared_ptr<Coord> platformCoord;
    std::shared_ptr<double> gravitationSpeed;
    Size doodleSize;
    Size platformSize;
    double jumpForce;
    std::shared_ptr<double> score;
    std::shared_ptr<double> lastScore;
    std::shared_ptr<int> jumpCounter;
};
