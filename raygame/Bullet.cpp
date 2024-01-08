#include "Bullet.h"
#include "Actor.h"

Bullet::Bullet(Actor* owner, MathLibrary::Vector2 position, MathLibrary::Vector2 velocity) : Actor(0, 0, "")
{
	m_owner = owner;
	m_velocity = velocity;
}

