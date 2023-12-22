#include "ProjectileComponent.h"
#include "CircleCollider.h"
#include "Actor.h"


ProjectileComponent::ProjectileComponent(Actor* owner, MathLibrary::Vector2 position, float projectileSpeed, const char* projectileSpritePath) : Component(owner, "ProjectileSpawnerComponent")
{
	m_owner = owner;
	m_projectileSpeed = projectileSpeed;
	m_projectileSpritePath = projectileSpritePath;
}

void ProjectileComponent::spawnProjectile()
{
	//Substitute Actor class with Bullet once it has been created
	Actor* bullet = new Actor(1, 1, "");

	CircleCollider* bulletCollider = new CircleCollider(2, bullet);
	bullet->setCollider(bulletCollider);
}
