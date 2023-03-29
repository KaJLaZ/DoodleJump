#pragma once
#include "AbilityConfig.h"
#include "EnemyConfig.h"
#include "PlatformConfig.h"
#include "ProjectileConfig.h"
#include "../utilities/ScreenResolution.h"

namespace config
{
    class ConfigResolutionAdjuster
    {
    public:
        ConfigResolutionAdjuster(ScreenResolution resolution) : resolution(resolution) {}

        DoodleConfig getAdjustedDoodleConfig(DoodleConfig&& config)
        {
            return DoodleConfig( config.spriteFilePath,
                adjustByWidthRes(config.posX), adjustByHeightRes(config.posY),
                adjustByWidthRes(config.width), adjustByHeightRes(config.height),
            adjustByWidthRes(config.moveDistance), adjustByHeightRes(config.gravitation),
            adjustByHeightRes(config.maxHeight), adjustByHeightRes(config.jumpForce));
        }

        PlatformConfig getAdjustedPlatformConfig(PlatformConfig&& config)
        {
            return PlatformConfig( config.spriteFilePath,
                adjustByWidthRes(config.posX), adjustByHeightRes(config.posY),
                adjustByWidthRes(config.width), adjustByHeightRes(config.height),
                config.platformAmount);
        }

        EnemyConfig getAdjustedEnemyConfig(EnemyConfig&& config)
        {
            return EnemyConfig( config.spriteFilePath,
                adjustByWidthRes(config.width), adjustByHeightRes(config.height),
                config.probability);
        }

        AbilityConfig getAdjustedAbilityConfig(AbilityConfig&& config)
        {
            return AbilityConfig( config.spriteFilePath,
                adjustByWidthRes(config.width), adjustByHeightRes(config.height),
                config.spawningJumpAmount);
        }

        ProjectileConfig getAdjustedProjectileConfig(ProjectileConfig&& config)
        {
            return ProjectileConfig( config.spriteFilePath,
                adjustByWidthRes(config.width), adjustByHeightRes(config.height),
                adjustByHeightRes(config.moveDistance));
        }

    private:
        ScreenResolution resolution;

        template<class T>
        T adjustByWidthRes(T& percentFromResolution)
        {
            return percentFromResolution * resolution.width / 100.0;
        }

        template<class T>
        int adjustByHeightRes(T& percentFromResolution)
        {
             return percentFromResolution * resolution.height / 100.0;
        }
    };
}
