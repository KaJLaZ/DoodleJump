#pragma once
#include "DoodleConfig.h"
#include "ConfigDeserializer.h"
#include "ConfigResolutionAdjuster.h"
#include "PlatformConfig.h"

namespace config
{
    class ConfigLoader
    {
    public:
        inline static const char* DOODLE_CONFIG_FILE_PATH = "resources/configs/DoodleConfig.json";
        inline static const char* PLATFORM_CONFIG_FILE_PATH = "resources/configs/PlatformConfig.json";
        inline static const char* ENEMY_CONFIG_FILE_PATH = "resources/configs/EnemyConfig.json";
        inline static const char* ABILITY_CONFIG_FILE_PATH = "resources/configs/AbilityConfig.json";
        inline static const char* PROJECTILE_CONFIG_FILE_PATH = "resources/configs/ProjectileConfig.json";

        ConfigLoader(ConfigResolutionAdjuster adjuster) : resolutionAdjuster(adjuster) {}

        DoodleConfig loadDoodleConfig()
        {
            return resolutionAdjuster.getAdjustedDoodleConfig(
                ConfigDeserializer::deserializeConfig<DoodleConfig>(DOODLE_CONFIG_FILE_PATH));
        }

        PlatformConfig loadPlatformConfig()
        {
            return resolutionAdjuster.getAdjustedPlatformConfig(
                ConfigDeserializer::deserializeConfig<PlatformConfig>(PLATFORM_CONFIG_FILE_PATH));
        }

        EnemyConfig loadEnemyConfig()
        {
            return resolutionAdjuster.getAdjustedEnemyConfig(
                ConfigDeserializer::deserializeConfig<EnemyConfig>(ENEMY_CONFIG_FILE_PATH));
        }

        AbilityConfig loadAbilityConfig()
        {
            return resolutionAdjuster.getAdjustedAbilityConfig(
                ConfigDeserializer::deserializeConfig<AbilityConfig>(ABILITY_CONFIG_FILE_PATH));
        }

        ProjectileConfig loadProjectileConfig()
        {
            return resolutionAdjuster.getAdjustedProjectileConfig(
                ConfigDeserializer::deserializeConfig<ProjectileConfig>(PROJECTILE_CONFIG_FILE_PATH));
        }

    private:
        ConfigResolutionAdjuster resolutionAdjuster;
    };
}
