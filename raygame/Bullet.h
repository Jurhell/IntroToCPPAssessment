#pragma once
#include "Transform2D.h"
class Actor;

class Bullet
{
public:
	Bullet(Actor owner, Transform2D position, const MathLibrary::Vector2 velocity);
	
private:
	bool m_started;
	Transform2D* m_transform;
	Actor m_owner;
	float m_damage;
	MathLibrary::Vector2 m_velocity;
};

