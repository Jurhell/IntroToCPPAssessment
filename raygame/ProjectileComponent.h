#pragma once
#include "Component.h"
#include "Bullet.h"
#include <Vector2.h>


class ProjectileComponent : public Component
{
public:
    /// <param name="owner">The owner for this spawner and it projectile.</param>
    /// <param name="position">The position of this spawner in relation to it's owner.</param>
    /// <param name="projectileSpeed">The speed the projectiles from this spawner will move at.</param>
    /// <param name="projectileSpritePath">The path the game will use to load sprite image.</param>
    ProjectileComponent(Actor* owner, MathLibrary::Vector2 position, float projectileSpeed, const char* projectileSpritePath);

    /// <summary>
    /// Creates a new instance of a projectile and adds it to the scene.
    /// </summary>
    void spawnProjectile();
private:
    Actor* m_owner;
    float m_projectileSpeed;
    const char* m_projectileSpritePath;
};

