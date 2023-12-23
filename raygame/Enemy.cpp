#include "Enemy.h"
#include "ActorArray.h"
#include "Transform2D.h"


Enemy::Enemy(Actor* target, const char* spritePath, MathLibrary::Vector2 position, float enemyRadius, float enemyView) : Actor(0, 0, "")
{
	m_target = target;
	m_enemyRadius = enemyRadius;
	m_enemyView = enemyView;
}

Enemy::~Enemy()
{
	delete m_target;
	delete m_test;
}

void Enemy::update()
{
	//Getting transforms for player and enemy
	Transform2D* test = m_target->getTransform();
	Transform2D* test2 = this->getTransform();

	//Subtracting player position from enemy position to get the distance between the two
	MathLibrary::Vector2 enemyToPlayer = test->getLocalPosition() - test2->getLocalPosition();

	//Normalizing the distance to prevent rubberbanding 
	MathLibrary::Vector2 playerDirection = enemyToPlayer.getNormalized();
}

void Enemy::draw()
{

}
