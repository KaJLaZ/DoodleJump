#pragma once
class Projectile
{
public:
    Projectile(std::string uuid, RenderNode renderNode, ProjectileMovementNode projectileMovementNode,
        ShootingEnemyNode shootingEnemyNode)
        : uuid(std::move(uuid)),
          renderNode(renderNode),
          projectileMovementNode(std::move(projectileMovementNode)),
          shootingEnemyNode(std::move(shootingEnemyNode)){}

    std::string getUUID()
    {
        return uuid;
    }

    RenderNode& getRenderNode()
    {
        return renderNode;
    }

    ProjectileMovementNode& getProjectileMovementNode()
    {
        return projectileMovementNode;
    }

    ShootingEnemyNode getShootingEnemyNode()
    {
        return shootingEnemyNode;
    }

private:
    std::string uuid;
    RenderNode renderNode;
    ProjectileMovementNode projectileMovementNode;
    ShootingEnemyNode shootingEnemyNode;
};
