#include "Bullet.h"
#include "Actor.h"

Bullet::Bullet(Actor owner, Transform2D position, const MathLibrary::Vector2 velocity)
{
	m_owner = owner;
	m_velocity = velocity;
}

