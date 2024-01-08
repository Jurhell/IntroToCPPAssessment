#include "SampleScene.h"
#include "SpriteComponent.h"
#include "Transform2D.h"
#include "Enemy.h"

void SampleScene::start()
{
	//This is a better comment
	Actor* test = new Actor(50, 50, "Test");
	test->addComponent(new SpriteComponent(test, "Images/player.png"));
	test->getTransform()->setScale({ 50, 50 });

	MathLibrary::Vector2 startPos = {75, 50};
	Enemy* jest = new Enemy(test, "Images/enemy.png", startPos, 0.5f, 50, 0);
	jest->addComponent(new SpriteComponent(jest, "Images/enemy.png"));
	jest->getTransform()->setScale({ 10, 10 });

	addActor(test);
	addActor(jest);
}

void SampleScene::update(float deltaTime)
{
}
