#include "Player.h"
#include "Actor.h"
#include "Transform2D.h"
#include "raylib.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "CircleCollider.h"
#include "Engine.h"
#include "ProjectileComponent.h"

Player::Player(const char* spritepath, float speed, float lives, MathLibrary::Vector2 position)
{
	m_speed = speed;
	m_lives = lives;
	m_position = position;
	m_gun = (ProjectileComponent*)this->addComponent(new ProjectileComponent(this, 175, "Images/bullet.png"));
	
	getTransform()->setLocalPosition(m_position);
	getTransform()->setForward({0,-1});

	//Attaching image to player
	SpriteComponent* spriteComponent = new SpriteComponent((Actor*)this, spritepath);

	//Creating circle collider for player
	//m_playerCollider = new CircleCollider(25, this);
	//this->setCollider(m_playerCollider);

	//Adding move component to player
	m_moveComponent = (MoveComponent*)this->addComponent(new MoveComponent(155, this));
}
Player::~Player()
{
	delete m_gun;
	delete m_playerCollider;
	delete m_moveComponent;
}
;

void Player::onDestroy()
{
	//takes away 1 life from the player
	m_lives--;
	m_position = {350, 750};

	if (m_lives >= 0)
	{
		Engine::CloseApplication();
	}
}

void Player::update(float deltaTime)
{
	Actor::update(deltaTime);
	MathLibrary::Vector2 m_direction;

	//Spawning projectiles using left mouse click
	if (RAYLIB_H::IsMouseButtonPressed(0))
		m_gun->spawnProjectile();

	//Setting the player character's direction using input from player
	if (RAYLIB_H::IsKeyDown(KeyboardKey::KEY_W))
	{
		m_direction = MathLibrary::Vector2(0, -1);
	}
	if (RAYLIB_H::IsKeyDown(KeyboardKey::KEY_S))
	{
		m_direction = MathLibrary::Vector2(0, 1);
	}
	if (RAYLIB_H::IsKeyDown(KeyboardKey::KEY_A))
	{
		m_direction = MathLibrary::Vector2(-1, 0);
	}
	if (RAYLIB_H::IsKeyDown(KeyboardKey::KEY_D))
	{
		m_direction = MathLibrary::Vector2(1, 0);
	}

	//Setting player's velocity using direction change above 
	m_moveComponent->setVelocity(m_direction * 100);
};