#pragma once
#include "Actor.h"
#include <Vector2.h>

class Enemy : public Actor
{
public:
	Enemy(Actor* target, const char* spritePath, MathLibrary::Vector2 position, float enemyRadius, float enemyView);
	~Enemy();

	void update();
	void draw();

private:
	Actor* m_target;
	Enemy* m_test;
	float m_enemyRadius;
	float m_enemyView;
};

