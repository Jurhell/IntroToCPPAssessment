#include "SampleScene.h"
#include "SpriteComponent.h"
#include "Transform2D.h"
#include "CircleCollider.h"
#include "Player.h"

void SampleScene::start()
{
	//This is a better comment
	Player* test = new Player("Images/player.png", 100, 3, {350, 750});
	test->addComponent(new SpriteComponent(test, "Images/player.png"));
	test->getTransform()->setScale({ 50, 50 });


	addActor(test);
}
