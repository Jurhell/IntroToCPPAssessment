#include "SampleScene.h"
#include "SpriteComponent.h"
#include "Transform2D.h"
#include "Enemy.h"
#include <iostream>

void SampleScene::start()
{
	Scene::start();

	//This is a better comment
	Actor* test = new Actor(250, 100, "Test");
	test->addComponent(new SpriteComponent(test, "Images/player.png"));
	test->getTransform()->setScale({ 50, 50 });
	
	MathLibrary::Vector2 startPos = { 100,100 };

	//Initializing enemy
	m_test = new Enemy(test, "Images/enemy.png", startPos, 0.5f, 250, 0);
	m_test->addComponent(new SpriteComponent(m_test, "Images/enemy.png"));
	m_test->getTransform()->setScale({ 50, 50 });

	addActor(test);
	addActor(m_test);
}

void SampleScene::update(float deltaTime)
{
	Scene::update(deltaTime);
	std::cout << "\nx position:" << m_test->getTransform()->getLocalPosition().x << std::endl;
	std::cout << "y position:" << m_test->getTransform()->getLocalPosition().y << std::endl;
}

void SampleScene::draw()
{

	Scene::draw();
}
