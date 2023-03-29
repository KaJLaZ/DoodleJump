#include <memory>
#include <utility>
#include <vector>
#include "../components/Size.h"
#include "../entities/Enemy.h"
#include "../entities/Platform.h"
#include "../utilities/RandomValueGenerator.h"

class EnemyGeneratorNode
{
public:
    EnemyGeneratorNode(Sprite* const sprite, const double probability, Size enemySize,
        std::shared_ptr<RandomValueGenerator> randomValueGenerator, std::shared_ptr<std::vector<Enemy>> enemies,
        std::shared_ptr<double> gravitationSpeed, ScreenResolution screenResolution,
        std::shared_ptr<std::vector<std::string>> removingUUID, std::shared_ptr<Coord> doodleCoord, Size doodleSize,
        std::shared_ptr<bool> isGameOver)
        : sprite(sprite),
          probability(probability),
          enemySize(enemySize),
          randomValueGenerator(std::move(randomValueGenerator)),
          enemies(std::move(enemies)),
          gravitationSpeed(std::move(gravitationSpeed)),
          screenResolution(screenResolution),
          removingUUID(std::move(removingUUID)),
          doodleCoord(std::move(doodleCoord)),
          doodleSize(doodleSize),
          isGameOver(std::move(isGameOver)){}

    double getProbability()
    {
        return probability;
    }

    Size getEnemySize()
    {
        return enemySize;
    }

    std::shared_ptr<RandomValueGenerator> getRandomValueGenerator()
    {
        return randomValueGenerator;
    }

    std::shared_ptr<std::vector<Enemy>> getEnemies()
    {
        return enemies;
    }

    Sprite* getSprite()
    {
        return sprite;
    }

    std::shared_ptr<double> getGravitationSpeed() const
    {
        return gravitationSpeed;
    }

    ScreenResolution getScreenResolution() const
    {
        return screenResolution;
    }

    std::shared_ptr<std::vector<std::string>> getRemovingUUID() const
    {
        return removingUUID;
    }

    std::shared_ptr<Coord> getDoodleCoord()
    {
        return doodleCoord;
    }

    Size getDoodleSize()
    {
        return doodleSize;
    }

    std::shared_ptr<bool> IsGameOver()
    {
        return isGameOver;
    }

private:
    Sprite* sprite;
    double probability;
    Size enemySize;
    std::shared_ptr<RandomValueGenerator> randomValueGenerator;
    std::shared_ptr<std::vector<Enemy>> enemies;
    std::shared_ptr<double> gravitationSpeed;
    ScreenResolution screenResolution;
    std::shared_ptr<std::vector<std::string>> removingUUID;
    std::shared_ptr<Coord> doodleCoord;
    Size doodleSize;
    std::shared_ptr<bool> isGameOver;
};
