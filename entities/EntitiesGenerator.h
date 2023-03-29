#pragma once
#include <string>
#include "../nodes/ProjectileGeneratorNode.h"

class EntitiesGenerator
{
public:
    EntitiesGenerator(std::string uuid, PlatformGeneratorNode platformGeneratorNode, EnemyGeneratorNode enemyGeneratorNode,
        AbilityGeneratorNode abilityGeneratorNode, ProjectileGeneratorNode projectileGeneratorNode)
        : uuid(std::move(uuid)),
          platformGeneratorNode(std::move(platformGeneratorNode)),
          enemyGeneratorNode(std::move(enemyGeneratorNode)),
          abilityGeneratorNode(std::move(abilityGeneratorNode)),
          projectileGeneratorNode(std::move(projectileGeneratorNode)){}

    std::string getUUID()
    {
        return uuid;
    }

    PlatformGeneratorNode& getPlatformGeneratorNode()
    {
        return platformGeneratorNode;
    }

    EnemyGeneratorNode& getEnemyGeneratorNode()
    {
        return enemyGeneratorNode;
    }

    AbilityGeneratorNode& getAbilityGeneratorNode()
    {
        return abilityGeneratorNode;
    }

    ProjectileGeneratorNode& getProjectileGeneratorNode()
    {
        return projectileGeneratorNode;
    }

private:
    std::string uuid;
    PlatformGeneratorNode platformGeneratorNode;
    EnemyGeneratorNode enemyGeneratorNode;
    AbilityGeneratorNode abilityGeneratorNode;
    ProjectileGeneratorNode projectileGeneratorNode;
};
