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
}

Enemy::~Enemy()
{
	delete m_target;
}

void Enemy::update(float deltaTime)
{;
    //Creating move component for enemy
	MoveComponent* enemyMove = (MoveComponent*)this->addComponent(new MoveComponent(10, this));

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

	//Moves enemy towards player after passing checks
	enemyMove->setVelocity(playerDirection * 100);
	test2->setLocalPosition(enemyMove->getVelocity() * deltaTime);

	////Creating projectile component for enemy 
	//ProjectileComponent* bulletSpawner = (ProjectileComponent*)this->addComponent(new ProjectileComponent(this, test2->getWorldPosition(), 5, "Images/bullet.png"));

	//m_currentTime += deltaTime;

	////Should fire a projectile after a certain amount of time has passed
	//if (m_currentTime >= m_fireTime)
	//	bulletSpawner->spawnProjectile();
}

//void Enemy::spawnEnemy()
//{
//	//Giving a circle collider to every actor added to scene
//	CircleCollider* enemyCollider = new CircleCollider(2, this);
//	this->setCollider(enemyCollider);
//}
