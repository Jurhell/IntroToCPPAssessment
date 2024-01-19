#include "SampleScene.h"
#include "SpriteComponent.h"
#include "Transform2D.h"
#include "Enemy.h"
#include <iostream>
#include "Player.h"

void SampleScene::start()
{
	Scene::start();

	//Initializing player
	m_player = new Player("Images/player.png", 100, 3, {350, 750});
	m_player->addComponent(new SpriteComponent(m_player, "Images/player.png"));
	m_player->getTransform()->setScale({ 50, 50 });
	
	//Creating enemy start positions
	MathLibrary::Vector2 startPos = { 350,50 };
	MathLibrary::Vector2 startPos2 = { 150,50 };
	MathLibrary::Vector2 startPos3 = { 550,50 };
	MathLibrary::Vector2 startPos4 = { 250,50 };
	MathLibrary::Vector2 startPos5 = { 450,50 };

	//Initializing enemies
	m_planet = new Enemy(m_player, "Images/");
	m_test = new Enemy(m_player, "Images/enemy.png", startPos);
	m_test2 = new Enemy(m_player, "Images/enemy.png", startPos2);
	m_test3 = new Enemy(m_player, "Images/enemy.png", startPos3);
	m_test4 = new Enemy(m_player, "Images/enemy.png", startPos4);
	m_test5 = new Enemy(m_player, "Images/enemy.png", startPos5);

	//Creating enemy array
	m_enemies = new Enemy*[5] { m_test, m_test2, m_test3, m_test4, m_test5 };

	//Adding player to scene
	addActor(m_player);
}

void SampleScene::update(float deltaTime)
{
	Scene::update(deltaTime);

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

	//Respawning player if destroyed
	if (m_player = nullptr)
		addActor(m_player);
}

