#pragma once
#include "SharedComponentsFabric.h"
#include "../utilities/ScreenResolution.h"
#include "../configs/ConfigLoader.h"
#include "../holders/ConfigsHolder.h"
#include "../holders/SharedComponentHolder.h"

using namespace config;

class HoldersFabric
{
public:
    static ConfigsHolder createConfigHolder(ScreenResolution resolution)
    {
        return { ConfigLoader(ConfigResolutionAdjuster(resolution))};
    }

    static SharedComponentHolder createSharedComponentHolder(std::shared_ptr<ConfigsHolder> configsHolder, ScreenResolution screenResolution)
    {
        return
        {
            SharedComponentsFabric::createDoodleCoord(configsHolder->getDoodleConfig()),
            SharedComponentsFabric::createMouseCoord(),
            SharedComponentsFabric::createPressedKey(),
            SharedComponentsFabric::createPressedMouseButton(),
            screenResolution,
            SharedComponentsFabric::createGravitationSpeed(configsHolder->getDoodleConfig().gravitation),
            SharedComponentsFabric::createPlatformsVector(),
            SharedComponentsFabric::createRandomValueGenerator(0,screenResolution.width - configsHolder->getPlatformConfig().width),
            SharedComponentsFabric::createRandomValueGenerator(screenResolution.height * 0.2,screenResolution.height),
            SharedComponentsFabric::createRandomValueGenerator(0, 100),
            SharedComponentsFabric::createRemovingUUIDList(),
            SharedComponentsFabric::createScore(),
            SharedComponentsFabric::createLastScore(),
            SharedComponentsFabric::createJumpCounter(),
            SharedComponentsFabric::createGameOver(),
            SharedComponentsFabric::enemies()
        };
    }
};