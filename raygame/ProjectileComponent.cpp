#include "ProjectileComponent.h"
#include "CircleCollider.h"
#include "Transform2D.h"
#include "Actor.h"


ProjectileComponent::ProjectileComponent(Actor* owner, MathLibrary::Vector2 position, float projectileSpeed, const char* projectileSpritePath) : Component(owner, "ProjectileSpawnerComponent")
{
	m_owner = owner;
	m_projectileSpeed = projectileSpeed;
	m_projectileSpritePath = projectileSpritePath;
}

void ProjectileComponent::spawnProjectile()
{
	//Getting the transform of the parent actor
	Transform2D* test = m_owner->getTransform();

	//Creating a new instance of a bullet
	Bullet* bullet = new Bullet(m_owner, test->getWorldPosition(), test->getForward() * m_projectileSpeed);

	CircleCollider* bulletCollider = new CircleCollider(2, bullet);
	bullet->setCollider(bulletCollider);
}
