#include <iostream>

#include "Framework.h"
#include "fabrics/ManagersFabric.h"
#include "fabrics/HoldersFabric.h"
#include "managers/EntityManager.h"
#include "managers/RemovingManager.h"
#include "managers/SystemManager.h"
#include "utilities/ScreenResolution.h"

/* Test Framework realization */
class MyFramework : public Framework {

public:
	std::shared_ptr<ScreenResolution> screenResolution;
	std::shared_ptr<EntityManager> entityManager;
	std::shared_ptr<SystemManager> systemManager;
	std::shared_ptr<RemovingManager> removingManager;
	
	virtual void PreInit(int& width, int& height, bool& fullscreen)
	{
		/*std::cout << "Input screen width" << std::endl;
		std::cin >> width;
		std::cout << "Input screen height" << std::endl;
		std::cin >> height;*/
		screenResolution = std::make_shared<ScreenResolution>(800, 600);
		width = screenResolution->width;
		height = screenResolution->height;
		fullscreen = false;
	}

	virtual bool Init() {

		auto configHolder = std::make_shared<ConfigsHolder>(HoldersFabric::createConfigHolder(*screenResolution));
		auto sharedComponentHolder = std::make_shared<SharedComponentHolder>(HoldersFabric::createSharedComponentHolder(configHolder, *screenResolution));
		entityManager = ManagersFabric::makeEntityManager(configHolder, sharedComponentHolder);
		systemManager = ManagersFabric::makeSystemManager();
		removingManager = ManagersFabric::makeRemovingManager(sharedComponentHolder->getRemovingUUID(), sharedComponentHolder->getEnemies(), systemManager);
		
		systemManager->getRenderSystem()->addNode(entityManager->getDoodle().getUUID(), entityManager->getDoodle().getRenderNode());
		systemManager->getMouseTrackSystem()->addNode(entityManager->getUserInputTracker().getUUID(), entityManager->getUserInputTracker().getMouseTrackNode());
		systemManager->getPlatformGeneratorSystem()->addNode(entityManager->getEntitiesGenerator().getUUID(), entityManager->getEntitiesGenerator().getPlatformGeneratorNode());
		systemManager->getPressedMouseButtonTrackSystem()->addNode(entityManager->getUserInputTracker().getUUID(), entityManager->getUserInputTracker().getPressedMouseButtonTrackSystem());
		systemManager->getEnemyGeneratorSystem()->addNode(entityManager->getEntitiesGenerator().getUUID(), entityManager->getEntitiesGenerator().getEnemyGeneratorNode());
		systemManager->getAbilityGeneratorSystem()->addNode(entityManager->getEntitiesGenerator().getUUID(), entityManager->getEntitiesGenerator().getAbilityGeneratorNode());
		systemManager->getProjectileGeneratorSystem()->addNode(entityManager->getEntitiesGenerator().getUUID(), entityManager->getEntitiesGenerator().getProjectileGeneratorNode());
		systemManager->getConstantXMoveSystem()->addNode(entityManager->getDoodle().getUUID(), entityManager->getDoodle().getConstantXMoveNode());
		systemManager->getPressedKeyTrackSystem()->addNode(entityManager->getUserInputTracker().getUUID(), entityManager->getUserInputTracker().getPressedKeyTrackNode());
		systemManager->getBeyondBoundaryMovingSystem()->addNode(entityManager->getBeyondBondaryMovingEntity().getUUID(), entityManager->getBeyondBondaryMovingEntity().getPlatformGeneratorNode());
		systemManager->getGravitationSystem()->addNode(entityManager->getDoodle().getUUID(), entityManager->getDoodle().getGravitationNode());
		systemManager->getHeightMonitoringSystem()->addNode(entityManager->getDoodle().getUUID(), entityManager->getDoodle().getHeightMonitoringNode());
		systemManager->getPlatformGeneratorSystem()->process();
		return true;
	}

	virtual void Close() {
	}

	virtual bool Tick() {
        drawTestBackground();
		systemManager->getGravitationSystem()->process();
		systemManager->getPickUpAbilitySystem()->process();
		systemManager->getAbilitySystem()->process();
		systemManager->getJumpOnEnemySystem()->process();
		systemManager->getShootingEnemySystem()->process();
		systemManager->getJumpSystem()->process();
		systemManager->getHeightMonitoringSystem()->process();
		systemManager->getBeyondBoundaryMovingSystem()->process();
		systemManager->getProjectileMovementSystem()->process();
		systemManager->getRenderSystem()->process();

		removingManager->removeNodes();

		if(*entityManager->getGameOverChecker().getGameOverCheckerNode().IsGameOver())
		{
			Init();
		}
		return false;
	}

	virtual void onMouseMove(int x, int y, int xrelative, int yrelative) {
		systemManager->getMouseTrackSystem()->process(Coord(x, y));
	}

	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased) {
		if(!isReleased)
		{
			systemManager->getPressedMouseButtonTrackSystem()->process(button);
			systemManager->getProjectileGeneratorSystem()->process();
		}

	}

	virtual void onKeyPressed(FRKey k) {
		systemManager->getPressedKeyTrackSystem()->process(k);
		systemManager->getConstantXMoveSystem()->process();
	}

	virtual void onKeyReleased(FRKey k) {
	}
	
	const char* GetTitle() override
	{
		return "DoodleJump";
	}

	void restart()
	{
		Init();
		//TODO remove dataleak provided by Sprite Raw Pointers
	}
};

int main(int argc, char *argv[])
{
	return run(new MyFramework);
}


