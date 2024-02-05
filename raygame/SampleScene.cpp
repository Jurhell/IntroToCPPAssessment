#include "SampleScene.h"
#include "SpriteComponent.h"
#include "Transform2D.h"
#include "Enemy.h"
#include <iostream>
#include "Player.h"
#include "raylib.h"

void SampleScene::start()
{
	Scene::start();

	//Initializing player, planet and child
	m_player = new Player("Images/player.png", 100, 3, {350, 750});
	m_player->addComponent(new SpriteComponent(m_player, "Images/player.png"));
	m_player->getTransform()->setScale({ 50, 50 });

	m_planet = new Actor(350, 10, "Images/planet.png");
	m_planet->addComponent(new SpriteComponent(m_planet, "Images/planet.png"));
	m_planet->getTransform()->setScale({ 150, 150 });

	m_child = new Actor(1, 1, "Images/enemy.png");
	m_child->addComponent(new SpriteComponent(m_child, "Images/enemy.png"));
	m_child->getTransform()->setScale({ .4f, .4f });
	

	//Creating enemy start positions
	MathLibrary::Vector2 startPos = { 350,50 };
	MathLibrary::Vector2 startPos2 = { 150,50 };
	MathLibrary::Vector2 startPos3 = { 550,50 };
	MathLibrary::Vector2 startPos4 = { 250,50 };
	MathLibrary::Vector2 startPos5 = { 450,50 };

	//Initializing enemies
	m_test = new Enemy(m_player, "Images/enemy.png", startPos);
	m_test2 = new Enemy(m_player, "Images/enemy.png", startPos2);
	m_test3 = new Enemy(m_player, "Images/enemy.png", startPos3);
	m_test4 = new Enemy(m_player, "Images/enemy.png", startPos4);
	m_test5 = new Enemy(m_player, "Images/enemy.png", startPos5);

	//Creating enemy array
	m_enemies = new Enemy*[5] { m_test, m_test2, m_test3, m_test4, m_test5 };

	Transform2D* test = m_planet->getTransform();
	Transform2D* test2 = m_child->getTransform();

	test->addChild(test2);

	//Adding player to scene
	addActor(m_player);
	addActor(m_planet);
	addActor(m_child);
}

void SampleScene::update(float deltaTime)
{
	Scene::update(deltaTime);

	m_planet->getTransform()->rotate(2 * deltaTime);
	m_child->getTransform()->rotate(2 * deltaTime);

	m_currentTime += deltaTime;

	//Spawning enemies in on a timer and putting a cap on the number of enemies
	if (m_currentTime >= m_timeToSpawn && m_enemiesInScene < 6)
	{
		addActor(m_enemies[m_currentEnemyIndex]);
		m_currentEnemyIndex++;
		m_enemiesInScene++;
		m_currentTime = 0;

		//Resetting enemy indexes to allow enemes to respawn
		if (m_currentEnemyIndex == 5)
			m_currentEnemyIndex = 0;
	    if (m_enemiesInScene == 5)
		    m_enemiesInScene = 0;
	}
	float i = 1;
	if (RAYLIB_H::IsKeyDown(KeyboardKey::KEY_E))
		m_planet->getTransform()->setScale({i,i});

	i++;

	//Respawning player if destroyed
	if (m_player = nullptr)
		addActor(m_player);
}

