#pragma once

#include "gameobject.h"
#include <vector>

using namespace sf;

class Player : public Gameobject {
public:
    Player();
    Player(Vector2f position);
    ~Player();

    void move(Vector2f pos) override;
    void update() override;

    void setSpeed(float speed);
    
    float getSpeed();

private:
    Vector2f endPoint;
    bool isMoving;
    float m_speed;
};
