#pragma once
#include <memory>
#include <utility>

class PickUpAbilityNode
{
public:
    PickUpAbilityNode(std::shared_ptr<Coord> doodleCoord, std::shared_ptr<Coord> abilityCoord, Size doodleSize,
        Size abilitySize, std::shared_ptr<std::vector<std::string>> removingUUID, std::string abilityUUID,
        std::shared_ptr<std::vector<Enemy>> enemies, std::shared_ptr<Coord> mouseCoord,
        std::shared_ptr<FRMouseButton> pressedMouseButton)
        : doodleCoord(std::move(doodleCoord)),
          abilityCoord(std::move(abilityCoord)),
          doodleSize(std::move(doodleSize)),
          abilitySize(std::move(abilitySize)),
          removingUUID(std::move(removingUUID)),
          abilityUUID(std::move(abilityUUID)),
          enemies(std::move(enemies)),
          mouseCoord(std::move(mouseCoord)),
          pressedMouseButton(std::move(pressedMouseButton)){}

    std::shared_ptr<Coord> getDoodleCoord()
    {
        return doodleCoord;
    }

    std::shared_ptr<Coord> getAbilityCoord()
    {
        return abilityCoord;
    }

    Size getDoodleSize()
    {
        return doodleSize;
    }

    Size getAbilitySize()
    {
        return abilitySize;
    }

    std::shared_ptr<std::vector<std::string>> getRemovingUUID()
    {
        return removingUUID;
    }

    std::string getAbilityUUID()
    {
        return abilityUUID;
    }

    std::shared_ptr<std::vector<Enemy>> getEnemies()
    {
        return enemies;
    }

    std::shared_ptr<Coord> getMouseCoord()
    {
        return mouseCoord;
    }

    std::shared_ptr<FRMouseButton> getPressedMouseButton()
    {
        return pressedMouseButton;
    }

private:
    std::shared_ptr<Coord> doodleCoord;
    std::shared_ptr<Coord> abilityCoord;
    Size doodleSize;
    Size abilitySize;
    std::shared_ptr<std::vector<std::string>> removingUUID;
    std::string abilityUUID;
    std::shared_ptr<std::vector<Enemy>> enemies;
    std::shared_ptr<Coord> mouseCoord;
    std::shared_ptr<FRMouseButton> pressedMouseButton;
};
