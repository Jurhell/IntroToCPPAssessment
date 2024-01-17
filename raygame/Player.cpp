#include "Player.h"
#include "Actor.h"
#include "Transform2D.h"
#include "raylib.h"
#include "SpriteComponent.h"

Player::Player(const char* spritepath, float speed, float health, MathLibrary::Vector2 position)
{
	speed = m_speed;
	health = m_health;
	
	SpriteComponent* spriteComponent = new SpriteComponent((Actor*)this, spritepath);
};

Player::~Player()
{
	delete this;
};

//void onCollision(Actor other)
//{
//
//};

void Update(float deltaTime)
{
	MathLibrary::Vector2 m_direction;

	if (RAYLIB_H::IsKeyDown(KeyboardKey::KEY_SPACE))
	{
		
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