#pragma once
#include <memory>
#include <utility>

class ShootingEnemyNode
{
public:
    ShootingEnemyNode(std::shared_ptr<Coord> projectileCoord, Size projectileSize, std::shared_ptr<std::vector<Enemy>> enemies,
        std::shared_ptr<std::vector<std::string>> removingUUID, std::string projectileUUID)
        : projectileCoord(std::move(projectileCoord)),
          projectileSize(projectileSize),
          enemies(std::move(enemies)),
          removingUUID(std::move(removingUUID)),
          projectileUUID(std::move(projectileUUID)){}

    std::shared_ptr<Coord> getProjectileCoord()
    {
        return projectileCoord;
    }

    void setProjectileCoord(double x, double y)
    {
        this->projectileCoord->setX(x);
        this->projectileCoord->setY(y);
    }

    Size getProjectileSize()
    {
        return projectileSize;
    }

    std::shared_ptr<std::vector<Enemy>> getEnemies()
    {
        return enemies;
    }

    std::shared_ptr<std::vector<std::string>> getRemovingUUID()
    {
        return removingUUID;
    }

    std::string getProjectileUUID()
    {
        return projectileUUID;
    }

private:
    std::shared_ptr<Coord> projectileCoord;
    Size projectileSize;
    std::shared_ptr<std::vector<Enemy>> enemies;
    std::shared_ptr<std::vector<std::string>> removingUUID;
    std::string projectileUUID;
};
