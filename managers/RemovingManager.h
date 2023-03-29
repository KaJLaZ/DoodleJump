#pragma once
#include <algorithm>
#include <utility>

class RemovingManager
{
public:
    RemovingManager(std::shared_ptr<std::vector<std::string>> removingUUID,
        std::shared_ptr<std::vector<Enemy>> enemies, std::shared_ptr<SystemManager> systemManager)
        : removingUUID(std::move(removingUUID)),
          enemies(std::move(enemies)),
          systemManager(std::move(systemManager)){}

    void removeNodes()
    {
        std::ranges::for_each(*removingUUID,[this] (std::string UUID)
        {
            systemManager->getRenderSystem()->removeNode(UUID);
            systemManager->getMouseTrackSystem()->removeNode(UUID);
            systemManager->getPressedKeyTrackSystem()->removeNode(UUID);
            systemManager->getPressedMouseButtonTrackSystem()->removeNode(UUID);
            systemManager->getPlatformGeneratorSystem()->removeNode(UUID);
            systemManager->getConstantXMoveSystem()->removeNode(UUID);
            systemManager->getBeyondBoundaryMovingSystem()->removeNode(UUID);
            systemManager->getGravitationSystem()->removeNode(UUID);
            systemManager->getHeightMonitoringSystem()->removeNode(UUID);
            systemManager->getPlatformMovingSystem()->removeNode(UUID);
            systemManager->getJumpSystem()->removeNode(UUID);
            systemManager->getEnemyGeneratorSystem()->removeNode(UUID);
            systemManager->getEnemyMovingSystem()->removeNode(UUID);
            systemManager->getAbilityGeneratorSystem()->removeNode(UUID);
            systemManager->getProjectileGeneratorSystem()->removeNode(UUID);
            systemManager->getProjectileMovementSystem()->removeNode(UUID);
            systemManager->getJumpOnEnemySystem()->removeNode(UUID);
            systemManager->getShootingEnemySystem()->removeNode(UUID);
            systemManager->getPickUpAbilitySystem()->removeNode(UUID);
            systemManager->getAbilitySystem()->removeNode(UUID);

            for (std::vector<Enemy>::iterator enemy = enemies->begin(); enemy != enemies->end();)
            {
                if (enemy->getUUID() == UUID)
                {
                    enemy = enemies->erase(enemy);
                }
                else
                {
                    ++enemy;
                }
            }
        });
        removingUUID->clear();
    }

private:
    std::shared_ptr<std::vector<std::string>> removingUUID;
    std::shared_ptr<std::vector<Enemy>> enemies;
    std::shared_ptr<SystemManager> systemManager;
};
