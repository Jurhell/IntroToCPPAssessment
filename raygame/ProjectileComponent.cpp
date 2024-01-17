#include "ProjectileComponent.h"
#include "Bullet.h"
#include "CircleCollider.h"
#include "Transform2D.h"
#include "Engine.h"
#include "Scene.h"


ProjectileComponent::ProjectileComponent(Actor* owner, float projectileSpeed, const char* projectileSpritePath) : Component(owner, "ProjectileSpawner")
{
	m_owner = owner;
	m_projectileSpeed = projectileSpeed;
	m_projectileSpritePath = projectileSpritePath;
}

void ProjectileComponent::spawnProjectile()
{
	//Creating variables to make code more readable
	MathLibrary::Vector2 velocity = m_owner->getTransform()->getForward() * m_projectileSpeed;
	MathLibrary::Vector2 position = m_owner->getTransform()->getWorldPosition() * 25;

	//Creating a new instance of a bullet
	Bullet* bullet = new Bullet(m_owner, position, velocity, "Images/bullet.png");

	//Giving bullet a collider and adding it to scene
	CircleCollider* bulletCollider = new CircleCollider(2, bullet);
	bullet->setCollider(bulletCollider);
	Engine::getCurrentScene()->addActor(bullet);
}
