#pragma once

#include <memory>
#include <utility>
#include "../Framework.h"
#include "../components/Coord.h"

class ProjectileGeneratorNode
{
public:
    ProjectileGeneratorNode(Size size, Sprite* sprite, std::shared_ptr<Coord> mouseCoord,
        std::shared_ptr<Coord> doodleCoord, std::shared_ptr<double> moveDistance,
        std::shared_ptr<FRMouseButton> pressedMouseButton, Size doodleSize, std::shared_ptr<std::vector<Enemy>> enemies,
        std::shared_ptr<std::vector<std::string>> removingUUID)
        : size(std::move(size)),
          sprite(std::move(sprite)),
          mouseCoord(std::move(mouseCoord)),
          doodleCoord(std::move(doodleCoord)),
          moveDistance(std::move(moveDistance)),
          pressedMouseButton(std::move(pressedMouseButton)),
          doodleSize(doodleSize),
          enemies(std::move(enemies)),
          removingUUID(std::move(removingUUID)){}

    Size getSize()
    {
        return size;
    }

    Sprite* getSprite()
    {
        return sprite;
    }

    Coord getMouseCoord()
    {
        return *mouseCoord;
    }

    Coord getDoodleCoord()
    {
        return *doodleCoord;
    }

    double getMoveDistance()
    {
        return *moveDistance;
    }

    FRMouseButton getPressedMouseButton()
    {
        return *pressedMouseButton;
    }

    Size getDoodleSize()
    {
        return doodleSize;
    }

    std::shared_ptr<std::vector<Enemy>> getEnemies()
    {
        return enemies;
    }

    std::shared_ptr<std::vector<std::string>> getRemovingUUID() const
    {
        return removingUUID;
    }

private:
    Size size;
    Sprite* sprite;
    std::shared_ptr<Coord> mouseCoord;
    std::shared_ptr<Coord> doodleCoord;
    std::shared_ptr<double> moveDistance;
    std::shared_ptr<FRMouseButton> pressedMouseButton;
    Size doodleSize;
    std::shared_ptr<std::vector<Enemy>> enemies;
    std::shared_ptr<std::vector<std::string>> removingUUID;
};
