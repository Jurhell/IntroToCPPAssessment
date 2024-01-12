#pragma once
#include "Transform2D.h"
#include "Actor.h"
#include "MoveComponent.h"

class Bullet : public Actor
{
public:
	Bullet(Actor* owner, MathLibrary::Vector2 position, MathLibrary::Vector2 velocity);

	void onCollision(Actor* other);
	
private:
	bool m_started;
	Transform2D* m_transform;
	Actor* m_owner;
	float m_damage;
	MathLibrary::Vector2 m_velocity;
};

