#include "../headers/player.h"
#include <SFML/System/Vector2.hpp>

Player::Player()
    : Gameobject()
    , isMoving(false)
    , m_speed(1.0f)
{
    ;
}

Player::Player(Vector2f position)
    : Gameobject(position, Vector2f(20, 20), "Player")
    , isMoving(false)
    , m_speed(1.0f)
{
    ;
}

Player::~Player() {
    ;
}

void Player::move(Vector2f pos) {
    endPoint = pos;
    isMoving = true;
    if(hasMoveEvent()) onMove(*this, pos);
}

void Player::update() {
    if(m_position.x == endPoint.x && m_position.y == endPoint.y) {
	isMoving = false;
	m_position.x = endPoint.x;
	m_position.y = endPoint.y;
    } else if(isMoving) {
	if(m_position.x < endPoint.x) m_position.x += m_speed;
	else if(m_position.x > endPoint.x) m_position.x -= m_speed;
	if(m_position.y < endPoint.y) m_position.y += m_speed;
	else if(m_position.y > endPoint.y) m_position.y -= m_speed;
	if((m_position.x - endPoint.x <= m_speed && m_position.x - endPoint.x >= -m_speed) || (m_position.x - endPoint.x >= m_speed && m_position.x - endPoint.x <= -m_speed))  m_position.x = endPoint.x;
	if((m_position.y - endPoint.y <= m_speed && m_position.y - endPoint.y >= -m_speed) || (m_position.y - endPoint.y >= m_speed && m_position.y - endPoint.y <= -m_speed))  m_position.y = endPoint.y;
    }
    m_collider.setPosition(m_position);
    if(hasTexture()) m_Sprite.setPosition(m_position);
    if(hasAnimation()) m_anim.update();
    if(hasUpdateEvent()) onUpdate(*this);
}

void Player::setSpeed(float speed) {
    m_speed = speed;
}

float Player::getSpeed() {
    return m_speed;
}
