#include "Enemy.h"
#include "ActorArray.h"
#include "Transform2D.h"
#include "CircleCollider.h"
//#include "MoveComponent.h"
#include <cmath>

Enemy::Enemy(Actor* target, const char* spritePath, MathLibrary::Vector2 position, float enemyRadius, float enemyView, float health) : Actor(0, 0, "")
{
	m_target = target;
	m_enemyRadius = enemyRadius;
	m_enemyView = enemyView;
	health = 10;
}

Enemy::~Enemy()
{
	delete m_target;
	delete m_test;
}

void Enemy::start()
{
	//Placeholder collider, may rework in future to work with actor array
	CircleCollider* enemyCollider = new CircleCollider(2, this);
	this->setCollider(enemyCollider);
}

void Enemy::update(float deltaTime)
{;
	//Getting transforms for player and enemy
	Transform2D* test = m_target->getTransform();
	Transform2D* test2 = this->getTransform();

	//Subtracting player position from enemy position to get the distance between the two
	MathLibrary::Vector2 enemyToPlayer = test->getLocalPosition() - test2->getLocalPosition();

	//Normalizing the distance to prevent rubberbanding 
	MathLibrary::Vector2 playerDirection = enemyToPlayer.getNormalized();

	float dotProduct = MathLibrary::Vector2::dotProduct(playerDirection, test2->getForward());

	double radians = acos(dotProduct);

	//Stops if player is behind enemy, out of view or outside of radius
	if (dotProduct <= 0)
		return;
	if (radians >= m_enemyRadius || test->getLocalPosition().x <= m_enemyView || test->getLocalPosition().y <= m_enemyView)
		return;

	//Moves enemy towards player after passing checks. Replace with Move Component once completed
	MathLibrary::Vector2 velocity = playerDirection * 100;
	test2->setLocalPosition(velocity * deltaTime);
}

void Enemy::draw()
{

}
