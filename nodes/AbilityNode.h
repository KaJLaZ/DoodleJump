#pragma once
#include <memory>
#include <utility>

#include "../Framework.h"

class AbilityNode
{
public:
    AbilityNode(std::shared_ptr<std::vector<Enemy>> enemies, std::shared_ptr<Coord> mouseCoord,
        std::shared_ptr<FRMouseButton> pressedMouseButton, std::shared_ptr<std::vector<std::string>> removingUUID,
        std::string enemyUUID)
        : enemies(std::move(enemies)),
          mouseCoord(std::move(mouseCoord)),
          pressedMouseButton(std::move(pressedMouseButton)),
          removingUUID(std::move(removingUUID)),
          enemyUUID(std::move(enemyUUID)){}

    std::shared_ptr<std::vector<Enemy>> getEnemies()
    {
        return enemies;
    }

    std::shared_ptr<Coord> getMouseCoord()
    {
        return mouseCoord;
    }

    void setMouseCoord(double x, double y)
    {
        this->mouseCoord->setX(x);
        this->mouseCoord->setY(y);
    }

    std::shared_ptr<FRMouseButton> getPressedMouseButton()
    {
        return pressedMouseButton;
    }

    void setPressedMouseButton(FRMouseButton button)
    {
        *this->pressedMouseButton = button;
    }

    std::shared_ptr<std::vector<std::string>> getRemovingUUID()
    {
        return removingUUID;
    }

    std::string getEnemyUUID()
    {
        return enemyUUID;
    }

private:
    std::shared_ptr<std::vector<Enemy>> enemies;
    std::shared_ptr<Coord> mouseCoord;
    std::shared_ptr<FRMouseButton> pressedMouseButton;
    std::shared_ptr<std::vector<std::string>> removingUUID;
    std::string enemyUUID;
};
