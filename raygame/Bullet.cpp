#include "Bullet.h"
#include "Actor.h"
#include "SpriteComponent.h"
#include "SampleScene.h"

Bullet::Bullet(Actor* owner, MathLibrary::Vector2 position, MathLibrary::Vector2 velocity, const char* spritepath) : Actor(position.x, position.y, spritepath)
{
	m_owner = owner;
	m_velocity = velocity;

	//Adding move component to bullets
	MoveComponent* moveComponent = new MoveComponent(175 ,this);
	addComponent(moveComponent);

	moveComponent->setVelocity(velocity);
	getTransform()->setLocalPosition(position);

	//Adding sprites to bullets
	SpriteComponent* spriteComponent = new SpriteComponent((Actor*)this, spritepath);
	addComponent(spriteComponent);
	getTransform()->setScale({ 10, 10 });
}

void Bullet::onCollision(Actor* other)
{
	//Checking if bullet has collided with owner
	if (other == m_owner)
		return;

	SampleScene* temp = new SampleScene();
	temp->removeActor(other);
}