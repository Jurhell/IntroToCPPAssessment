#include "MoveComponent.h"
#include "Transform2D.h"
#include "Actor.h"


MoveComponent::MoveComponent(float maxSpeed, Actor* owner) : Component(owner, "MoveComponet")
{
	m_maxSpeed = maxSpeed;
}

void MoveComponent::update(float deltaTime)
{
	//Storing the current position
	MathLibrary::Vector2 position = getOwner()->getTransform()->getLocalPosition();

	//Checking if the velocity exceeds the maximum speed
	if (getVelocity().getMagnitude() > getMaxSpeed())
	{
		//If it does normalize the velocity and scale it by the max speed
		MathLibrary::Vector2 newVelocity = getVelocity().getNormalized() * getMaxSpeed();
		setVelocity(newVelocity);
	}

	//Increase the current position by the velocity to get the new position
	position = position + getVelocity() * deltaTime;

	//Set the transform's position to be the new position
	getOwner()->getTransform()->setLocalPosition(position);
}
