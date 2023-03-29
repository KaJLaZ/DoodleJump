#pragma once
#include <algorithm>
#include <unordered_map>
#include <utility>
#include "EnemyMovingSystem.h"
#include "JumpOnEnemySystem.h"
#include "PickUpAbilitySystem.h"
#include "RenderSystem.h"
#include "../components/Size.h"
#include "../utilities/UUID.h"

class AbilityGeneratorSystem : InputSystem<AbilityGeneratorNode, Coord>
{
public:
    AbilityGeneratorSystem(std::shared_ptr<RenderSystem> renderSystem,
        std::shared_ptr<EnemyMovingSystem> enemyMovingSystem,
        std::shared_ptr<PickUpAbilitySystem> pickUpAbilitySystem,
        std::unordered_map<std::string, AbilityGeneratorNode> nodes)
        : renderSystem(std::move(renderSystem)),
          enemyMovingSystem(std::move(enemyMovingSystem)),
          pickUpAbilitySystem(std::move(pickUpAbilitySystem)),
          nodes(std::move(nodes)){}

    void addNode(std::string&& uuid, AbilityGeneratorNode& node)
    {
        nodes.emplace(std::make_pair(uuid, node));
    }

    void process(Coord platformCoord)
    {
        std::ranges::for_each(nodes, [this, &platformCoord](std::pair<const std::string, AbilityGeneratorNode> pair)
            {
                if(*pair.second.getJumpCounter() == pair.second.getSpawningJumpAmount())
                {
                    *pair.second.getJumpCounter() = 0;
                    auto abilitySize = pair.second.getSize();
                    auto abilityCoord = std::make_shared<Coord>(Coord(platformCoord.getX(), platformCoord.getY() - abilitySize.getHeigth()));

                    auto enemyUUID = UUID::generate();
                    RenderNode renderNode = NodesFabric::makeRenderNode(pair.second.getSprite(),
                        abilityCoord, abilitySize);
                    EnemyMovingNode enemyMovingNode = NodesFabric::makeEnemyMovingNode(pair.second.getGravitationSpeed(),
                        pair.second.getScreenResolution(), abilityCoord, pair.second.getRemovingUUID(), enemyUUID);
                    PickUpAbilityNode pickUpAbilityNode(pair.second.getDoodleCoord(), abilityCoord, pair.second.getDoodleSize(),
                        abilitySize, pair.second.getRemovingUUID(), enemyUUID, pair.second.getEnemies(),
                        pair.second.getMouseCoord(), pair.second.getMouseButton());
                    
                    renderSystem->addNode(enemyUUID.c_str(), renderNode);
                    enemyMovingSystem->addNode(enemyUUID.c_str(), enemyMovingNode);
                    pickUpAbilitySystem->addNode(enemyUUID.c_str(), pickUpAbilityNode);
                }
            });
    }

    void removeNode(std::string key)
    {
        nodes.erase(key);
    }

private:
    std::shared_ptr<RenderSystem> renderSystem;
    std::shared_ptr<EnemyMovingSystem> enemyMovingSystem;
    std::shared_ptr<PickUpAbilitySystem> pickUpAbilitySystem;
    std::unordered_map<std::string, AbilityGeneratorNode> nodes;
};
