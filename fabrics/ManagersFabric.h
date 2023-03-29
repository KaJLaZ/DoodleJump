#include <memory>
#include <memory>

#include "NodesFabric.h"
#include "EntitiesFabric.h"
#include "../Framework.h"
#include "../managers/SystemManager.h"
#include "../systems/RenderSystem.h"
#include "../systems/MouseTrackSystem.h"
#include "../systems/PressedKeyTrackSystem.h"
#include "../nodes/PressedKeyTrackNode.h"
#include "../managers/EntityManager.h"
#include "../holders/SharedComponentHolder.h"
#include "../holders/ConfigsHolder.h"
#include "../managers/RemovingManager.h"
#include "../systems/PressedMouseButtonTrackSystem.h"
#include "../utilities/UUID.h"

class ManagersFabric
{
public:
    static std::shared_ptr<EntityManager> makeEntityManager(std::shared_ptr<config::ConfigsHolder> configsHolder,
        std::shared_ptr<SharedComponentHolder> sharedCompHolder)
    {
        auto doodleConfig = configsHolder->getDoodleConfig();
        auto platformConfig = configsHolder->getPlatformConfig();
        auto enemyConfig = configsHolder->getEnemyConfig();
        auto abilityConfig = configsHolder->getAbilityConfig();
        auto projectileConfig = configsHolder->getProjectileConfig();

        auto doodleSize = Size(doodleConfig.width, doodleConfig.height);
        auto platformSize = Size(platformConfig.width, platformConfig.height);
        auto enemySize = Size(enemyConfig.width, enemyConfig.height);
        auto abilitySize = Size(abilityConfig.width, abilityConfig.height);
        auto projectileSize = Size(projectileConfig.width, projectileConfig.height);
        
        Sprite* doodleSprite(createSprite(doodleConfig.spriteFilePath.c_str()));
        
        Sprite* platformSprite(createSprite(platformConfig.spriteFilePath.c_str()));
        Sprite* enemySprite(createSprite(enemyConfig.spriteFilePath.c_str()));
        Sprite* abilitySprite(createSprite(abilityConfig.spriteFilePath.c_str()));
        Sprite* projectileSprite(createSprite(projectileConfig.spriteFilePath.c_str()));

        auto doodleRenderNode = NodesFabric::makeRenderNode(doodleSprite, sharedCompHolder->getDoodleCoord(), doodleSize);
        auto doodleConstantXMoveNode = NodesFabric::makeConstantXMoveNode(
            sharedCompHolder->getDoodleCoord(), std::make_shared<int>(doodleConfig.moveDistance), sharedCompHolder->getPressedKey());
        auto doodleGraviatationNode = NodesFabric::makeGravitationNode(sharedCompHolder->getDoodleCoord(), sharedCompHolder->getGravitation());
        auto doodleHeightMonitoringNode = NodesFabric::makeHeightMonitoringNode(
        sharedCompHolder->getDoodleCoord(), doodleConfig.maxHeight, sharedCompHolder->getScore(), sharedCompHolder->getScreenResolution(), sharedCompHolder->IsGameOver());

        auto beyondBondaryMovingNode = NodesFabric::makeBeyondBondaryMovingNode(sharedCompHolder->getDoodleCoord(), sharedCompHolder->getScreenResolution(), doodleSize);
        
        auto mouseTrackNode = NodesFabric::makeMouseTrackNode(sharedCompHolder->getMouseCoord());
        auto pressedKeyNode = NodesFabric::makePressedKeyNode(sharedCompHolder->getPressedKey());
        auto pressedMouseButtonTrackNode = NodesFabric::makePressedMouseButtonTrackNode(sharedCompHolder->getPressedMouseButton());
        
        auto platformGeneratorNode = NodesFabric::makePlatformGeneratorNode(platformSprite, platformSize, doodleSize,
            sharedCompHolder->getScreenResolution(), sharedCompHolder->getPlatforms(), platformConfig.platformAmount,
            sharedCompHolder->getGravitation(), sharedCompHolder->getPlatformXCordRandomValueGenerator(),
            sharedCompHolder->getPlatformYCordRandomValueGenerator(), sharedCompHolder->getDoodleCoord(), doodleConfig.jumpForce,
            sharedCompHolder->getScore(), sharedCompHolder->getLastScore(), sharedCompHolder->getJumpCounter());
        auto enemyGeneratorNode = NodesFabric::makeEnemyGeneratorNode(enemySprite, enemyConfig.probability, enemySize,
            sharedCompHolder->getEnemyRandomValueGenerator(), sharedCompHolder->getEnemies(),
            sharedCompHolder->getGravitation(), sharedCompHolder->getScreenResolution(), sharedCompHolder->getRemovingUUID(),
            sharedCompHolder->getDoodleCoord(), doodleSize, sharedCompHolder->IsGameOver());
        auto abilityGeneratorNode = NodesFabric::makeAbilityGeneratorNode(abilitySprite, abilitySize, sharedCompHolder->getPlatforms(),
            sharedCompHolder->getGravitation(), sharedCompHolder->getScreenResolution(), sharedCompHolder->getRemovingUUID(),
            sharedCompHolder->getJumpCounter(), abilityConfig.spawningJumpAmount, sharedCompHolder->getDoodleCoord(),
            doodleSize, sharedCompHolder->getEnemies(), sharedCompHolder->getMouseCoord(), sharedCompHolder->getPressedMouseButton());
        auto projectileGeneratorNode = NodesFabric::makeProjectileGeneratorNode(projectileSize, projectileSprite,
            sharedCompHolder->getMouseCoord(), sharedCompHolder->getDoodleCoord(),
            std::make_shared<double>(projectileConfig.moveDistance),
            sharedCompHolder->getPressedMouseButton(), doodleSize, sharedCompHolder->getEnemies(), sharedCompHolder->getRemovingUUID());
        
        GameOverCheckerNode gameOverCheckerNode(sharedCompHolder->IsGameOver());

        
        Doodle doodle(EntitiesFabric::makeDoodleEntity(
            UUID::generate(), doodleRenderNode, doodleConstantXMoveNode, doodleGraviatationNode, doodleHeightMonitoringNode));
        UserInputTracker userInputTracker(EntitiesFabric::makeUserInputTrackerEntity(
            UUID::generate(), mouseTrackNode, pressedKeyNode, pressedMouseButtonTrackNode));
        EntitiesGenerator entitiesGenerator(EntitiesFabric::makeEntitiesGenerator(
            UUID::generate(), platformGeneratorNode, enemyGeneratorNode, abilityGeneratorNode, projectileGeneratorNode));
        BeyondBondaryMovingEntity beyondBondaryMovingEntity(
            EntitiesFabric::makeBeyondBondaryMovingEntity(UUID::generate(), beyondBondaryMovingNode));
        GameOverChecker gameOverChecker(EntitiesFabric::makeGameOverChecker(UUID::generate(), gameOverCheckerNode));
        
        EntityManager entityManager(doodle, userInputTracker, entitiesGenerator, beyondBondaryMovingEntity, gameOverChecker);
        
        return std::make_shared<EntityManager>(entityManager);
    }

    static std::shared_ptr<SystemManager> makeSystemManager()
    {
        auto renderSystem = std::make_shared<RenderSystem>(RenderSystem(std::unordered_map<std::string, RenderNode>()));
        auto mouseTrackSystem = std::make_shared<MouseTrackSystem>(MouseTrackSystem(std::unordered_map<std::string, MouseTrackNode>()));
        auto pressedKeyTrackSystem = std::make_shared<PressedKeyTrackSystem>(PressedKeyTrackSystem(std::unordered_map<std::string, PressedKeyTrackNode>()));
        auto pressedMouseButtonTrackSystem = std::make_shared<PressedMouseButtonTrackSystem>(PressedMouseButtonTrackSystem(std::unordered_map<std::string, PressedMouseButtonTrackNode>()));
        auto constantXMoveSystem = std::make_shared<ConstantXMoveSystem>(ConstantXMoveSystem(std::unordered_map<std::string, ConstantXMoveNode>()));
        auto beyondBoundaryMovingSystem = std::make_shared<BeyondBoundaryMovingSystem>(BeyondBoundaryMovingSystem(std::unordered_map<std::string, BeyondBondaryMovingNode>()));
        auto gravitationSystem = std::make_shared<GravitationSystem>(GravitationSystem(std::unordered_map<std::string, GravitationNode>()));
        auto jumpSystem = std::make_shared<JumpSystem>(JumpSystem(std::unordered_map<std::string, JumpNode>()));
        auto enemyMovingSystem = std::make_shared<EnemyMovingSystem>(EnemyMovingSystem(std::unordered_map<std::string, EnemyMovingNode>()));
        auto jumpOnEnemySystem = std::make_shared<JumpOnEnemySystem>(JumpOnEnemySystem(std::unordered_map<std::string, JumpOnEnemyNode>()));
        auto enemyGeneratorSystem = std::make_shared<EnemyGeneratorSystem>(EnemyGeneratorSystem(renderSystem, enemyMovingSystem, jumpOnEnemySystem, std::unordered_map<std::string, EnemyGeneratorNode>()));
        auto projectileMovementSystem = std::make_shared<ProjectileMovementSystem>(ProjectileMovementSystem(std::unordered_map<std::string, ProjectileMovementNode>()));
        auto shootingEnemySystem = std::make_shared<ShootingEnemySystem>(ShootingEnemySystem(std::unordered_map<std::string, ShootingEnemyNode>()));
        auto projectileGeneratorSystem = std::make_shared<ProjectileGeneratorSystem>(ProjectileGeneratorSystem(renderSystem, projectileMovementSystem, shootingEnemySystem, std::unordered_map<std::string, ProjectileGeneratorNode>()));
        auto abilitySystem = std::make_shared<AbilitySystem>(AbilitySystem(projectileGeneratorSystem, std::unordered_map<std::string, AbilityNode>()));
        auto pickUpAbilitySystem = std::make_shared<PickUpAbilitySystem>(PickUpAbilitySystem(abilitySystem, std::unordered_map<std::string, PickUpAbilityNode>()));
        auto abilityGeneratorSystem = std::make_shared<AbilityGeneratorSystem>(AbilityGeneratorSystem(renderSystem, enemyMovingSystem, pickUpAbilitySystem, std::unordered_map<std::string, AbilityGeneratorNode>()));       
        auto platformMovingSystem = std::make_shared<PlatformMovingSystem>(PlatformMovingSystem(enemyGeneratorSystem, abilityGeneratorSystem, std::unordered_map<std::string, PlatformMovingNode>()));
        auto heightMonitoringSystem = std::make_shared<HeightMonitoringSystem>(HeightMonitoringSystem(platformMovingSystem, enemyMovingSystem, std::unordered_map<std::string, HeightMonitoringNode>()));
        auto platformGeneratorSystem = std::make_shared<PlatformGeneratorSystem>(PlatformGeneratorSystem(jumpSystem, renderSystem, platformMovingSystem, std::unordered_map<std::string, PlatformGeneratorNode>()));


        
        return std::make_shared<SystemManager>(SystemManager(renderSystem, mouseTrackSystem, pressedKeyTrackSystem,
            pressedMouseButtonTrackSystem, platformGeneratorSystem, constantXMoveSystem, beyondBoundaryMovingSystem,
            gravitationSystem, heightMonitoringSystem, platformMovingSystem, jumpSystem, enemyGeneratorSystem, enemyMovingSystem,
            abilityGeneratorSystem, projectileGeneratorSystem, projectileMovementSystem, jumpOnEnemySystem, shootingEnemySystem,
            pickUpAbilitySystem, abilitySystem));
    }

    static std::shared_ptr<RemovingManager> makeRemovingManager(std::shared_ptr<std::vector<std::string>> removingUUID,
        std::shared_ptr<std::vector<Enemy>> enemies, std::shared_ptr<SystemManager> systemManager)
    {
        return std::make_shared<RemovingManager>(removingUUID, enemies, systemManager);
    }
};
