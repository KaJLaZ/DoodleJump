#pragma once
#include <memory>
#include <utility>

class JumpOnEnemyNode
{
public:
    JumpOnEnemyNode(std::shared_ptr<Coord> doodleCoord, std::shared_ptr<Coord> enemyCoord,
        std::shared_ptr<double> gravitationSpeed, Size doodleSize, Size enemySize, std::shared_ptr<bool> isGameOver,
        std::shared_ptr<std::vector<std::string>> removingUUID, std::string enemyUUID)
        : doodleCoord(std::move(doodleCoord)),
          enemyCoord(std::move(enemyCoord)),
          gravitationSpeed(std::move(gravitationSpeed)),
          doodleSize(doodleSize),
          enemySize(enemySize),
          isGameOver(std::move(isGameOver)),
          removingUUID(std::move(removingUUID)),
          enemyUUID(std::move(enemyUUID)){}

    std::shared_ptr<Coord> getDoodleCoord()
    {
        return doodleCoord;
    }

    void setEnemyCoord(double x, double y)
    {
        this->enemyCoord->setX(x);
        this->enemyCoord->setY(y);
    }

    std::shared_ptr<Coord> getEnemyCoord()
    {
        return enemyCoord;
    }

    std::shared_ptr<double> getGravitationSpeed()
    {
        return gravitationSpeed;
    }

    Size getDoodleSize()
    {
        return doodleSize;
    }

    Size getEnemySize()
    {
        return enemySize;
    }

    std::shared_ptr<bool> IsGameOver()
    {
        return isGameOver;
    }

    std::shared_ptr<std::vector<std::string>> getRemovingUUID() const
    {
        return removingUUID;
    }

    std::string getEnemyUUID() const
    {
        return enemyUUID;
    }

private:
    std::shared_ptr<Coord> doodleCoord;
    std::shared_ptr<Coord> enemyCoord;
    std::shared_ptr<double> gravitationSpeed;
    Size doodleSize;
    Size enemySize;
    std::shared_ptr<bool> isGameOver;
    std::shared_ptr<std::vector<std::string>> removingUUID;
    std::string enemyUUID;
};
