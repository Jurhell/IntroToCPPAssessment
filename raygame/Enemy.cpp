#include "Enemy.h"
#include "ActorArray.h"
#include "Transform2D.h"
#include "CircleCollider.h"
#include "MoveComponent.h"
#include "ProjectileComponent.h"
#include <cmath>

Enemy::Enemy(Actor* target, const char* spritePath, MathLibrary::Vector2 position, float enemyRadius, float enemyView, float health) : Actor(0, 0, "")
{
	m_target = target;
	m_enemyRadius = enemyRadius;
	m_enemyView = enemyView;
	health = 10;
	getTransform()->setLocalPosition({ position });

	//Adding move component to enemy
	m_enemyMove = (MoveComponent*)this->addComponent(new MoveComponent(10, this));

	//Adding collider to enemy
	m_enemyCollider = new CircleCollider(50, this);
	this->setCollider(m_enemyCollider);

	//Addding projectile spawner to enemy
	m_bulletSpawner = (ProjectileComponent*)this->addComponent(new ProjectileComponent(this, target->getTransform()->getWorldPosition(), 5, "Images/bullet.png"));
}

Enemy::~Enemy()
{
	delete m_target;
	delete m_enemyMove;
	delete m_enemyCollider;
	delete m_bulletSpawner;
}

void Enemy::update(float deltaTime)
{
	Actor::update(deltaTime);

	//Getting transforms for player and enemy
	Transform2D* test = m_target->getTransform();

	//Subtracting player position from enemy position to get the distance between the two
	MathLibrary::Vector2 enemyToPlayer = test->getLocalPosition() - getTransform()->getLocalPosition();

	//Normalizing the distance to prevent rubberbanding 
	MathLibrary::Vector2 playerDirection = enemyToPlayer.getNormalized();

	float dotProduct = MathLibrary::Vector2::dotProduct(playerDirection, getTransform()->getForward());

	double radians = acos(dotProduct);

	m_currentTime += deltaTime;

	//Should fire a projectile after a certain amount of time has passed
	if (m_currentTime >= m_fireTime)
		m_bulletSpawner->spawnProjectile();

	//Stops if player is behind enemy, out of view or outside of radius
	if (dotProduct <= 0 || radians >= m_enemyRadius)
		return;
	//if (test->getLocalPosition().x >= m_enemyView && test->getLocalPosition().y >= m_enemyView)
	//	return;

	//Moves enemy towards player after passing checks
	m_enemyMove->setVelocity(playerDirection * 100);
	getTransform()->setLocalPosition(m_enemyMove->getVelocity() * deltaTime);
	getTransform()->setForward(playerDirection);


}

