#include "SampleScene.h"
#include "SpriteComponent.h"
#include "Transform2D.h"
#include "Enemy.h"
#include <iostream>

void SampleScene::start()
{
	Scene::start();

	//This is a better comment
	Actor* test = new Actor(350, 750, "Test");
	test->addComponent(new SpriteComponent(test, "Images/player.png"));
	test->getTransform()->setScale({ 50, 50 });
	
	MathLibrary::Vector2 startPos = { 350,50 };
	MathLibrary::Vector2 startPos2 = { 150,50 };
	MathLibrary::Vector2 startPos3 = { 550,50 };
	MathLibrary::Vector2 startPos4 = { 250,50 };
	MathLibrary::Vector2 startPos5 = { 450,50 };

	//Initializing enemies
	m_test = new Enemy(test, "Images/enemy.png", startPos, 1);
	m_test2 = new Enemy(test, "Images/enemy.png", startPos2, 1);
	m_test3 = new Enemy(test, "Images/enemy.png", startPos3, 1);
	m_test4 = new Enemy(test, "Images/enemy.png", startPos4, 1);
	m_test5 = new Enemy(test, "Images/enemy.png", startPos5, 1);

	m_enemies = new Enemy*[5] { m_test, m_test2, m_test3, m_test4, m_test5 };

	addActor(test);
}

void SampleScene::update(float deltaTime)
{
	Scene::update(deltaTime);

	//Printing enemy position to console
	//std::cout << "\nx position:" << m_test->getTransform()->getLocalPosition().x << std::endl;
	//std::cout << "y position:" << m_test->getTransform()->getLocalPosition().y << std::endl;

	m_currentTime += deltaTime;

	if (m_currentTime >= m_timeToSpawn && m_enemiesInScene < 6)
	{
		addActor(m_enemies[m_currentEnemyIndex]);
		m_currentEnemyIndex++;
		m_enemiesInScene++;
		m_currentTime = 0;

		if (m_currentEnemyIndex == 5)
			m_currentEnemyIndex = 0;
	}
}

void SampleScene::draw()
{
	Scene::draw();
}
