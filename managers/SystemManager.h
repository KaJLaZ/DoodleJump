#pragma once
#include "../systems/AbilitySystem.h"
#include "../systems/MouseTrackSystem.h"
#include "../systems/PlatformGeneratorSystem.h"
#include "../systems/PressedKeyTrackSystem.h"
#include "../systems/RenderSystem.h"
#include "../systems/ConstantXMoveSystem.h"
#include "../systems/BeyondBoundaryMovingSystem.h"
#include "../systems/GravitationSystem.h"
#include "../systems/HeightMonitoringSystem.h"
#include "../systems/JumpSystem.h"
#include "../systems/PickUpAbilitySystem.h"
#include "../systems/PressedMouseButtonTrackSystem.h"
#include "../systems/ProjectileMovementSystem.h"
#include "../systems/ProjectileGeneratorSystem.h"
#include "../systems/ShootingEnemySystem.h"

class SystemManager
{
public:
    SystemManager(std::shared_ptr<RenderSystem> renderSystem, std::shared_ptr<MouseTrackSystem> mouseTrackSystem,
        std::shared_ptr<PressedKeyTrackSystem> pressedKeyTrackSystem,
        std::shared_ptr<PressedMouseButtonTrackSystem> pressedMouseButtonTrackSystem,
        std::shared_ptr<PlatformGeneratorSystem> platformGeneratorSystem,
        std::shared_ptr<ConstantXMoveSystem> constantXMoveSystem, std::shared_ptr<BeyondBoundaryMovingSystem> beyondBoundaryMovingSystem,
        std::shared_ptr<GravitationSystem> gravitationSystem, std::shared_ptr<HeightMonitoringSystem> heightMonitoringSystem,
        std::shared_ptr<PlatformMovingSystem> platformMovingSystem, std::shared_ptr<JumpSystem> jumpSystem,
        std::shared_ptr<EnemyGeneratorSystem> enemyGeneratorSystem, std::shared_ptr<EnemyMovingSystem> enemyMovingSystem,
        std::shared_ptr<AbilityGeneratorSystem> abilityGeneratorSystem, std::shared_ptr<ProjectileGeneratorSystem> projectileGeneratorSystem,
        std::shared_ptr<ProjectileMovementSystem> projectileMovementSystem, std::shared_ptr<JumpOnEnemySystem> jumpOnEnemySystem,
        std::shared_ptr<ShootingEnemySystem> shootingEnemySystem, std::shared_ptr<PickUpAbilitySystem> pickUpAbilitySystem,
        std::shared_ptr<AbilitySystem> abilitySystem)
        : renderSystem(std::move(renderSystem)),
        mouseTrackSystem(std::move(mouseTrackSystem)),
        pressedKeyTrackSystem(std::move(pressedKeyTrackSystem)),
        pressedMouseButtonTrackSystem(std::move(pressedMouseButtonTrackSystem)),
        platformGeneratorSystem(std::move(platformGeneratorSystem)),
        constantXMoveSystem(std::move(constantXMoveSystem)),
        beyondBoundaryMovingSystem(std::move(beyondBoundaryMovingSystem)),
        gravitationSystem(std::move(gravitationSystem)),
        heightMonitoringSystem(std::move(heightMonitoringSystem)),
        platformMovingSystem(std::move(platformMovingSystem)),
        jumpSystem(std::move(jumpSystem)),
        enemyGeneratorSystem(std::move(enemyGeneratorSystem)),
        enemyMovingSystem(std::move(enemyMovingSystem)),
        abilityGeneratorSystem(std::move(abilityGeneratorSystem)),
        projectileGeneratorSystem(std::move(projectileGeneratorSystem)),
        projectileMovementSystem(std::move(projectileMovementSystem)),
        jumpOnEnemySystem(std::move(jumpOnEnemySystem)),
        shootingEnemySystem(std::move(shootingEnemySystem)),
        pickUpAbilitySystem(std::move(pickUpAbilitySystem)),
        abilitySystem(std::move(abilitySystem)){}

    std::shared_ptr<RenderSystem> getRenderSystem()
    {
        return renderSystem;
    }

    std::shared_ptr<MouseTrackSystem> getMouseTrackSystem()
    {
        return mouseTrackSystem;
    }

    std::shared_ptr<PressedKeyTrackSystem> getPressedKeyTrackSystem()
    {
        return pressedKeyTrackSystem;
    }

    std::shared_ptr<PressedMouseButtonTrackSystem> getPressedMouseButtonTrackSystem()
    {
        return pressedMouseButtonTrackSystem;
    }

    std::shared_ptr<PlatformGeneratorSystem> getPlatformGeneratorSystem()
    {
        return platformGeneratorSystem;
    }

    std::shared_ptr<ConstantXMoveSystem> getConstantXMoveSystem()
    {
        return constantXMoveSystem;
    }

    std::shared_ptr<BeyondBoundaryMovingSystem> getBeyondBoundaryMovingSystem()
    {
        return beyondBoundaryMovingSystem;
    }

    std::shared_ptr<GravitationSystem> getGravitationSystem()
    {
        return gravitationSystem;
    }

    std::shared_ptr<HeightMonitoringSystem> getHeightMonitoringSystem()
    {
        return heightMonitoringSystem;
    }

    std::shared_ptr<PlatformMovingSystem> getPlatformMovingSystem()
    {
        return platformMovingSystem;
    }

    std::shared_ptr<JumpSystem> getJumpSystem()
    {
        return jumpSystem;
    }

    std::shared_ptr<EnemyGeneratorSystem> getEnemyGeneratorSystem()
    {
        return enemyGeneratorSystem;
    }

    std::shared_ptr<EnemyMovingSystem> getEnemyMovingSystem()
    {
        return enemyMovingSystem;
    }

    std::shared_ptr<AbilityGeneratorSystem> getAbilityGeneratorSystem()
    {
        return abilityGeneratorSystem;
    }

    std::shared_ptr<ProjectileGeneratorSystem> getProjectileGeneratorSystem()
    {
        return projectileGeneratorSystem;
    }

    std::shared_ptr<ProjectileMovementSystem> getProjectileMovementSystem()
    {
        return projectileMovementSystem;
    }

    std::shared_ptr<JumpOnEnemySystem> getJumpOnEnemySystem()
    {
        return jumpOnEnemySystem;
    }

    std::shared_ptr<ShootingEnemySystem> getShootingEnemySystem()
    {
        return shootingEnemySystem;
    }

    std::shared_ptr<PickUpAbilitySystem> getPickUpAbilitySystem()
    {
        return pickUpAbilitySystem;
    }

    std::shared_ptr<AbilitySystem> getAbilitySystem()
    {
        return abilitySystem;
    }

private:
    std::shared_ptr<RenderSystem> renderSystem;
    std::shared_ptr<MouseTrackSystem> mouseTrackSystem;
    std::shared_ptr<PressedKeyTrackSystem> pressedKeyTrackSystem;
    std::shared_ptr<PressedMouseButtonTrackSystem> pressedMouseButtonTrackSystem;
    std::shared_ptr<PlatformGeneratorSystem> platformGeneratorSystem;
    std::shared_ptr<ConstantXMoveSystem> constantXMoveSystem;
    std::shared_ptr<BeyondBoundaryMovingSystem> beyondBoundaryMovingSystem;
    std::shared_ptr<GravitationSystem> gravitationSystem;
    std::shared_ptr<HeightMonitoringSystem> heightMonitoringSystem;
    std::shared_ptr<PlatformMovingSystem> platformMovingSystem;
    std::shared_ptr<JumpSystem> jumpSystem;
    std::shared_ptr<EnemyGeneratorSystem> enemyGeneratorSystem;
    std::shared_ptr<EnemyMovingSystem> enemyMovingSystem;
    std::shared_ptr<AbilityGeneratorSystem> abilityGeneratorSystem;
    std::shared_ptr<ProjectileGeneratorSystem> projectileGeneratorSystem;
    std::shared_ptr<ProjectileMovementSystem> projectileMovementSystem;
    std::shared_ptr<JumpOnEnemySystem> jumpOnEnemySystem;
    std::shared_ptr<ShootingEnemySystem> shootingEnemySystem;
    std::shared_ptr<PickUpAbilitySystem> pickUpAbilitySystem;
    std::shared_ptr<AbilitySystem> abilitySystem;
};
