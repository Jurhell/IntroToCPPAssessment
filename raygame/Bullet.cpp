#include "Bullet.h"
#include "Actor.h"
#include "SpriteComponent.h"
#include "Engine.h"

Bullet::Bullet(Actor* owner, MathLibrary::Vector2 position, MathLibrary::Vector2 velocity, const char* spritepath) : Actor(position.x, position.y, spritepath)
{
	MoveComponent* moveComponent = new MoveComponent(100 ,owner);
	addComponent(moveComponent);

	m_owner = owner;
	m_velocity = velocity;

	moveComponent->setVelocity(velocity);
	getTransform()->setLocalPosition(position);

	SpriteComponent* spriteComponent = new SpriteComponent((Actor*)this, spritepath);
}

void Bullet::onCollision(Actor* other)
{
	if (other == m_owner)
		return;

	Engine::destroy(other);
}