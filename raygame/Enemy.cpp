#include "Enemy.h"
#include "Actor.h"
#include "ActorArray.h"
#include "Transform2D.h"
#include "CircleCollider.h"
#include "MoveComponent.h"
#include "ProjectileComponent.h"
#include "SpriteComponent.h"
#include <cmath>

Enemy::Enemy() : Actor(0, 0, "")
{
	m_target = nullptr;
}

Enemy::Enemy(Actor* target, const char* spritePath, MathLibrary::Vector2 position) : Actor(0, 0, "")
{
	m_target = target;
	getTransform()->setLocalPosition({ position });

	//Adding move component to enemy
	m_enemyMove = (MoveComponent*)this->addComponent(new MoveComponent(150, this));

	//Adding collider to enemy
	m_enemyCollider = new CircleCollider(50, this);
	this->setCollider(m_enemyCollider);

	//Addding projectile spawner to enemy
	m_bulletSpawner = (ProjectileComponent*)this->addComponent(new ProjectileComponent(this, 175, "Images/bullet.png"));

	//Adding sprite and setting enemy scale
	addComponent(new SpriteComponent(this, "Images/enemy.png"));
	getTransform()->setScale({ 62, 62 });
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
	{
		m_bulletSpawner->spawnProjectile();
		m_currentTime = 0;
	}

	//Moves enemy towards player after passing checks
	m_enemyMove->setVelocity(playerDirection * 80);
	getTransform()->lookAt(test->getLocalPosition());


}

