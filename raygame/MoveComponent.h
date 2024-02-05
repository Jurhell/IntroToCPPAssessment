#pragma once
#include "Component.h"
#include "Vector2.h"
class Actor;

class MoveComponent :
    public Component
{
public:
    MoveComponent(float maxSpeed, Actor* owner);

    //Initializing get and set functions for an actor's velocity
    MathLibrary::Vector2 getVelocity() { return m_velocity; }
    void setVelocity(MathLibrary::Vector2 velocity) { m_velocity = velocity; }

    //Initializing get and set functions for an actor's max speed
    float getMaxSpeed() { return m_maxSpeed; }
    void setMaxSpeed(float maxSpeed) { m_maxSpeed = maxSpeed; }

    void update(float deltaTime) override;

private:
    float m_maxSpeed;
    MathLibrary::Vector2 m_velocity;
};

