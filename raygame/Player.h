#include "Actor.h"
#include "Transform2D.h"


class Player : public Actor
{
public:
	Player(const char* spritepath, float speed, float health, MathLibrary::Vector2 position);
	~Player();

	/// <summary>
	/// Will calaculate health/life loss on collsion with another object.
	/// </summary>
	//void onCollision(Actor other) override;

	/// <summary>
	/// Contains button attachment to movement and shooting along with speed/velocity management.
	/// </summary>
	void Update(float deltaTime);

private:
	float m_speed;
	float m_health;
};