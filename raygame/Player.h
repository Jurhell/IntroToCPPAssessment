#include "Actor.h"
#include "Transform2D.h"
class CircleCollider;
class MoveComponent;
class ProjectileComponent;

class Player : public Actor
{
public:
	Player(const char* spritepath, float speed, float lives, MathLibrary::Vector2 position);
	~Player();

	/// <summary>
	/// Contains button attachment to movement and shooting along with speed/velocity management.
	/// </summary>
	void update(float deltaTime) override;

	void onDestroy() override;

	bool m_result;
private:
	float m_speed;
	float m_lives;

	MathLibrary::Vector2 m_position;
	ProjectileComponent* m_gun;
	CircleCollider* m_playerCollider;
	MoveComponent* m_moveComponent;
	
};