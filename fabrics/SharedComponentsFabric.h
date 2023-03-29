#pragma once
#include <memory>
#include "../holders/ConfigsHolder.h"
#include "../components/Coord.h"

class SharedComponentsFabric
{
public:
    static std::shared_ptr<Coord> createDoodleCoord(config::DoodleConfig doodleConfig)
    {
        return std::make_shared<Coord>(Coord(doodleConfig.posX, doodleConfig.posY));
    }
    
    static std::shared_ptr<Coord> createMouseCoord()
    {
        return std::make_shared<Coord>(Coord(0, 0));
    }
    
    static std::shared_ptr<FRKey> createPressedKey()
    {
        return std::make_shared<FRKey>(FRKey::UP);
    }

    static std::shared_ptr<FRMouseButton> createPressedMouseButton()
    {
        return std::make_shared<FRMouseButton>(FRMouseButton::COUNT);
    }

    static std::shared_ptr<double> createGravitationSpeed(double gravitationSpeed)
    {
        return std::make_shared<double>(gravitationSpeed);
    }

    static std::shared_ptr<std::vector<Platform>> createPlatformsVector()
    {
        return std::make_shared<std::vector<Platform>>();
    }

    static std::shared_ptr<RandomValueGenerator> createRandomValueGenerator(int min, int max)
    {
        auto seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::default_random_engine randomEngine(seed);
        std::uniform_int_distribution<unsigned> valueDistribution(min,  max);
        return std::make_shared<RandomValueGenerator>(randomEngine, valueDistribution);
    }

    static std::shared_ptr<std::vector<std::string>> createRemovingUUIDList()
    {
        std::vector<std::string> vector;
        return std::make_shared<std::vector<std::string>>(vector);
    }

    static std::shared_ptr<double> createScore()
    {
        return std::make_shared<double>();
    }

    static std::shared_ptr<double> createLastScore()
    {
        return std::make_shared<double>();
    }

    static std::shared_ptr<int> createJumpCounter()
    {
        return std::make_shared<int>();
    }

    static std::shared_ptr<bool> createGameOver()
    {
        return std::make_shared<bool>(false);
    }

    static std::shared_ptr<std::vector<Enemy>> enemies()
    {
        return std::make_shared<std::vector<Enemy>>();
    }
};
