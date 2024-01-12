#include "Bullet.h"
#include "Actor.h"
#include "SpriteComponent.h"
#include "Engine.h"

Bullet::Bullet(Actor* owner, MathLibrary::Vector2 position, MathLibrary::Vector2 velocity) : Actor(0, 0, "")
{
	MoveComponent* moveComponent = new MoveComponent(100 ,owner);
	addComponent(moveComponent);

	m_owner = owner;
	m_velocity = velocity;

	moveComponent->setVelocity(velocity);
	getTransform()->setLocalPosition(position);

	SpriteComponent*
}

void Bullet::onCollision(Actor* other)
{
	if (other == m_owner)
		return;

	Engine::destroy(other);
}