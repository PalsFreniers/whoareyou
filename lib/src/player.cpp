#include "../headers/player.h"
#include <SFML/System/Vector2.hpp>

Player::Player()
    : Gameobject()
    , isMoving(false)
    , m_speed(2.0f)
{
    ;
}

Player::Player(Vector2f position)
    : Gameobject(position, Vector2f(), "Player")
    , isMoving(false)
    , m_speed(2.0f)
{
    ;
}

void Player::move(Vector2f pos) {
    endPoint = pos;
    isMoving = true;
    if(hasMoveEvent()) onMove(*this, pos);
}

void Player::update() {
    if(m_position == endPoint) isMoving = false;
    if(isMoving) {
	if(m_position.x < endPoint.x) m_position.x += m_speed;
	else if(m_position.x > endPoint.x) m_position.y -= m_speed;
	if(m_position.y < endPoint.y) m_position.y += m_speed;
	else if(m_position.y > endPoint.y) m_position.y -= m_speed;
    }
    if(hasAnimation()) m_anim.update();
    if(hasUpdateEvent()) onUpdate(*this);
}

void Player::setSpeed(float speed) {
    m_speed = speed;
}

float Player::getSpeed() {
    return m_speed;
}
