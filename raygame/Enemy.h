#pragma once
#include "Actor.h"
#include <Vector2.h>
class MoveComponent;
class CircleCollider;
class ProjectileComponent;

class Enemy : public Actor
{
public:
	Enemy(Actor* target, const char* spritePath, MathLibrary::Vector2 position, float enemyRadius, float enemyView, float health);
	~Enemy();

	void update(float deltaTime) override;

private:
	Actor* m_target;
	MoveComponent* m_enemyMove;
	CircleCollider* m_enemyCollider;
	ProjectileComponent* m_bulletSpawner;
	float m_enemyRadius;
	float m_enemyView;
	float m_currentTime;
	float m_fireTime = 1.5f;
};

