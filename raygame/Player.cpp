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
	speed = m_speed;
	lives = m_lives;
	
	//Attaching image to player
	SpriteComponent* spriteComponent = new SpriteComponent((Actor*)this, spritepath);

	//Creating circle collider for player
	m_playerCollider = new CircleCollider(25, this);
	this->setCollider(m_playerCollider);

	m_moveComponent = (MoveComponent*)this->addComponent(new MoveComponent(100, this));
};

void Player::onDestroy()
{
	//takes away 1 life from the player
	m_lives--;

	if (m_lives >= 0)
	{
		Engine::CloseApplication();
	}
}

void Player::update(float deltaTime)
{
	MathLibrary::Vector2 m_direction;

	//Get key input from player
	if (RAYLIB_H::IsMouseButtonPressed(0))
	{
		m_gun->spawnProjectile();
	}
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
};