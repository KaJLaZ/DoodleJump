#pragma once
#include "../configs/DoodleConfig.h"
#include "../configs/ConfigLoader.h"

namespace config
{
    class ConfigsHolder
    {
    public:
        ConfigsHolder(ConfigLoader configLoader) : configLoader(configLoader) {}

        DoodleConfig getDoodleConfig()
        {
            if (doodleConfig == nullptr)
            {
                doodleConfig = std::make_unique<DoodleConfig>(configLoader.loadDoodleConfig());
            }
            return *doodleConfig;
        }

        PlatformConfig getPlatformConfig()
        {
            if (platformConfig == nullptr)
            {
                platformConfig = std::make_unique<PlatformConfig>(configLoader.loadPlatformConfig());
            }
            return *platformConfig;
        }

        EnemyConfig getEnemyConfig()
        {
            if (enemyConfig == nullptr)
            {
                enemyConfig = std::make_unique<EnemyConfig>(configLoader.loadEnemyConfig());
            }
            return *enemyConfig;
        }

        AbilityConfig getAbilityConfig()
        {
            if (abilityConfig == nullptr)
            {
                abilityConfig = std::make_unique<AbilityConfig>(configLoader.loadAbilityConfig());
            }
            return *abilityConfig;
        }

        ProjectileConfig getProjectileConfig()
        {
            if (projectileConfig == nullptr)
            {
                projectileConfig = std::make_unique<ProjectileConfig>(configLoader.loadProjectileConfig());
            }
            return *projectileConfig;
        }

    private:
        ConfigLoader configLoader;
        std::unique_ptr<DoodleConfig> doodleConfig;
        std::unique_ptr<PlatformConfig> platformConfig;
        std::unique_ptr<EnemyConfig> enemyConfig;
        std::unique_ptr<AbilityConfig> abilityConfig;
        std::unique_ptr<ProjectileConfig> projectileConfig;
    };
}
