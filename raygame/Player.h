#include "Actor.h"
#include "Transform2D.h"

class Player
{
public:
	Player(const char* spritepath, Vector2 positionX, Vector2 positionY);

	void OnCollision(Actor other);

	void Update(float deltaTime);

private:
	float m_speed;

};