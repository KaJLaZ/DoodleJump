#include <memory>
#include <utility>
#include <vector>
#include "../components/Size.h"
#include "../entities/Enemy.h"
#include "../entities/Platform.h"

class AbilityGeneratorNode
{
public:
    AbilityGeneratorNode(Sprite* sprite, Size size, std::shared_ptr<std::vector<Platform>> platforms,
        std::shared_ptr<double> gravitationSpeed, ScreenResolution screenResolution,
        std::shared_ptr<std::vector<std::string>> removingUUID, std::shared_ptr<int> jumpCounter,
        const int spawningJumpAmount, std::shared_ptr<Coord> doodleCoord, Size doodleSize,
        std::shared_ptr<std::vector<Enemy>> enemies, std::shared_ptr<Coord> mouseCoord,
        std::shared_ptr<FRMouseButton> mouseButton)
        : sprite(sprite),
          size(std::move(size)),
          platforms(std::move(platforms)),
          gravitationSpeed(std::move(gravitationSpeed)),
          screenResolution(std::move(screenResolution)),
          removingUUID(std::move(removingUUID)),
          jumpCounter(std::move(jumpCounter)),
          spawningJumpAmount(spawningJumpAmount),
          doodleCoord(std::move(doodleCoord)),
          doodleSize(std::move(doodleSize)),
          enemies(std::move(enemies)),
          mouseCoord(std::move(mouseCoord)),
          mouseButton(std::move(mouseButton)){}

    Sprite* getSprite()
    {
        return sprite;
    }

    Size getSize()
    {
        return size;
    }

    std::shared_ptr<std::vector<Platform>> getPlatforms()
    {
        return platforms;
    }

    std::shared_ptr<double> getGravitationSpeed()
    {
        return gravitationSpeed;
    }

    ScreenResolution getScreenResolution()
    {
        return screenResolution;
    }

    std::shared_ptr<std::vector<std::string>> getRemovingUUID()
    {
        return removingUUID;
    }

    std::shared_ptr<int> getJumpCounter()
    {
        return jumpCounter;
    }

    int getSpawningJumpAmount()
    {
        return spawningJumpAmount;
    }

    std::shared_ptr<Coord> getDoodleCoord()
    {
        return doodleCoord;
    }

    Size getDoodleSize()
    {
        return doodleSize;
    }

    std::shared_ptr<std::vector<Enemy>> getEnemies()
    {
        return enemies;
    }

    std::shared_ptr<Coord> getMouseCoord()
    {
        return mouseCoord;
    }

    std::shared_ptr<FRMouseButton> getMouseButton()
    {
        return mouseButton;
    }

private:
    Sprite* sprite;
    Size size;
    std::shared_ptr<std::vector<Platform>> platforms;
    std::shared_ptr<double> gravitationSpeed;
    ScreenResolution screenResolution;
    std::shared_ptr<std::vector<std::string>> removingUUID;
    std::shared_ptr<int> jumpCounter;
    int spawningJumpAmount;
    std::shared_ptr<Coord> doodleCoord;
    Size doodleSize;
    std::shared_ptr<std::vector<Enemy>> enemies;
    std::shared_ptr<Coord> mouseCoord;
    std::shared_ptr<FRMouseButton> mouseButton;
    
};
