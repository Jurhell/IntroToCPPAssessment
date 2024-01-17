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
    Enemy* m_test2;
    Enemy* m_test3;
    Enemy* m_test4;
    Enemy* m_test5;
    Enemy** m_enemies;
    int m_currentEnemyIndex = 0;
    float m_currentTime;
    float m_timeToSpawn = 2;
    float m_enemiesInScene;
};

