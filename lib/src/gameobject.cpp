#include "../headers/gameobjects.h"
#include <SFML/System/Vector2.hpp>
#include <ios>

Gameobject::Gameobject(sf::Vector2f position, sf::Vector2f size, std::string name) :
      m_name(name),
      m_position(position),
      m_size(size),
      m_anim(1, 1, "placeholder.png",false, false)
{
    m_collider.setPosition(m_position);
    m_collider.setSize(m_size);
}

bool Gameobject::setTexture(std::string TexturePath) {
    hasTexture = m_texture.loadFromFile(TexturePath);
    return hasTexture;
}

void Gameobject::setVisible(bool visible) {
    isVisible = visible;
}

void Gameobject::setAnimation(Animation anim) {
    m_anim = anim;
    hasAnimation = true;
}

void Gameobject::update() {
    if (hasUpdateEvent) onUpdate(*this);
    if (hasAnimation) { m_anim.update(); m_anim.setPosition(m_position);}
}

bool Gameobject::checkCollide(Gameobject &other) {
    if (hasCollideEvent) onCollide(*this, other);
    if (m_position.x + m_size.x/2 < other.getPosition().x - other.getSize().x/2) return 0;
    if (m_position.x - m_size.x/2 > other.getPosition().x + other.getSize().x/2) return 0;
    if (m_position.y + m_size.y/2 < other.getPosition().y - other.getSize().y/2) return 0;
    if (m_position.y - m_size.y/2 > other.getPosition().y + other.getSize().y/2) return 0;
    return 1;
}

void Gameobject::setRectangleColor(sf::Color c) {
    m_collider.setFillColor(c);
}

void Gameobject::draw(sf::RenderWindow &window) {
    if(hasDrawEvent) onDraw(*this, window);
    if(hasAnimation) m_anim.draw(window);
    else if(hasTexture) window.draw(m_Sprite);
    else window.draw(m_collider);
}

void Gameobject::move(sf::Vector2f vel) {
    if(hasMoveEvent) onMove(*this, vel);
    m_position.x += vel.x; m_position.y += vel.y;
    m_collider.setPosition(m_position);
}

void Gameobject::setUpdateEvent(std::function<void (Gameobject &)> onUpdateEvent) {
    onUpdate = onUpdateEvent;
    hasUpdateEvent = true;
}

void Gameobject::setDrawEvent(std::function<void (Gameobject &, sf::RenderWindow)> onDrawEvent) {
    onDraw = onDrawEvent;
    hasDrawEvent = true;
}

void Gameobject::setMoveEvent(std::function<void (Gameobject &, sf::Vector2f)> onMoveEvent) {
    onMove = onMoveEvent;
    hasMoveEvent = true;
}

void Gameobject::setCollideEvent(std::function<void (Gameobject &, Gameobject &)> onCollideEvent) {
    onCollide = onCollideEvent;
    hasCollideEvent = true;
}
