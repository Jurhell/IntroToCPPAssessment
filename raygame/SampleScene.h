#pragma once
#include "Scene.h"
class Enemy;

class SampleScene :
    public Scene
{
public:
    void start() override;
    void update(float deltaTime) override;
    void draw() override;

private:
    ActorArray m_actors;
    Enemy* m_test;
};

