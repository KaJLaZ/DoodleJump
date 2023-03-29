#pragma once

class EntityManager
{
public:
    EntityManager( Doodle doodle, UserInputTracker tracker, EntitiesGenerator entitiesGenerator,
        BeyondBondaryMovingEntity beyondBondaryMovingEntity, GameOverChecker gameOverChecker)
        : doodle(std::move(doodle)),
        userInputTracker(std::move(tracker)),
        entitiesGenerator(std::move(entitiesGenerator)),
        beyondBondaryMovingEntity(std::move(beyondBondaryMovingEntity)),
        gameOverChecker(std::move(gameOverChecker)){}

    Doodle getDoodle()
    {
        return doodle;
    }

    UserInputTracker getUserInputTracker()
    {
        return userInputTracker;
    }

    EntitiesGenerator getPlatformGenerator()
    {
        return entitiesGenerator;
    }

    BeyondBondaryMovingEntity getBeyondBondaryMovingEntity()
    {
        return beyondBondaryMovingEntity;
    }

    EntitiesGenerator getEntitiesGenerator()
    {
        return entitiesGenerator;
    }

    GameOverChecker getGameOverChecker() const
    {
        return gameOverChecker;
    }

private:
    Doodle doodle;
    UserInputTracker userInputTracker;
    EntitiesGenerator entitiesGenerator;
    BeyondBondaryMovingEntity beyondBondaryMovingEntity;
    GameOverChecker gameOverChecker;
};
