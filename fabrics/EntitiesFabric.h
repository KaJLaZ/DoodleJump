#include "../entities/UserInputTracker.h"
#include "../entities/Doodle.h"
#include "../entities/EntitiesGenerator.h"
#include "../entities/BeyondBondaryMovingEntity.h"
#include "../entities/Enemy.h"
#include "../entities/GameOverChecker.h"
#include "../entities/Projectile.h"

class EntitiesFabric
{
public:

    static UserInputTracker makeUserInputTrackerEntity(std::string uuid, MouseTrackNode mouseTrackNode,
        PressedKeyTrackNode pressedKeyTrackNode, PressedMouseButtonTrackNode pressedMouseButtonTrackNode)
    {
        return { std::move(uuid), std::move(mouseTrackNode), std::move(pressedKeyTrackNode), pressedMouseButtonTrackNode };
    }

    static Doodle makeDoodleEntity(std::string uuid, RenderNode renderNode, ConstantXMoveNode constantXMoveNode,
        GravitationNode gravitationNode, HeightMonitoringNode heightMonitoringNode)
    {
        return { std::move(uuid), std::move(renderNode), constantXMoveNode, gravitationNode, heightMonitoringNode};
    }

    static Platform makePlatformEntity(std::string uuid, RenderNode renderNode, PlatformMovingNode platformMovingNode,
        JumpNode jumpNode)
    {
        return {std::move(uuid), std::move(renderNode), std::move(platformMovingNode), jumpNode};
    }

    static EntitiesGenerator makeEntitiesGenerator(std::string uuid, PlatformGeneratorNode platformGeneratorNode,
        EnemyGeneratorNode enemyGeneratorNode, AbilityGeneratorNode abilityGeneratorNode,
        ProjectileGeneratorNode projectileGeneratorNode)
    {
        return { std::move(uuid), std::move(platformGeneratorNode) , std::move(enemyGeneratorNode), std::move(abilityGeneratorNode),
            std::move(projectileGeneratorNode)
        };
    }

    static BeyondBondaryMovingEntity makeBeyondBondaryMovingEntity(std::string uuid, BeyondBondaryMovingNode beyondBondaryMovingNode)
    {
        return { std::move(uuid), std::move(beyondBondaryMovingNode) };
    }

    static Enemy makeEnemyEntity(std::string uuid, RenderNode renderNode, EnemyMovingNode enemyMovingNode,
        JumpOnEnemyNode jumpOnEnemyNode)
    {
        return { std::move(uuid), std::move(renderNode), std::move(enemyMovingNode), std::move(jumpOnEnemyNode)};
    }

    static Projectile makeProjectileEntity(std::string uuid, RenderNode renderNode,
        ProjectileMovementNode projectileMovementNode, ShootingEnemyNode shootingEnemyNode)
    {
        return { std::move(uuid), std::move(renderNode), std::move(projectileMovementNode), std::move(shootingEnemyNode)};
    }

    static GameOverChecker makeGameOverChecker(std::string uuid, GameOverCheckerNode gameOverCheckerNode)
    {
        return { std::move(uuid), std::move(gameOverCheckerNode) };
    }
};
