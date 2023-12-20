#include "Enemy.h"


Enemy::Enemy(Actor* target, const char* spritePath, MathLibrary::Vector2 position, float enemyRadius, float enemyView)
{
	m_target = target;
	m_enemyRadius = enemyRadius;
	m_enemyView = enemyView;
}

Enemy::~Enemy()
{
	delete m_target;
}

void Enemy::update()
{

}

void Enemy::draw()
{

}
