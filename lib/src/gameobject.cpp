#include "../headers/gameobjects.h"
#include <SFML/System/Vector2.hpp>

Gameobject::Gameobject(sf::Vector2f position, sf::Vector2f size, std::string name) :
      m_name(name),
      m_position(position),
      m_size(size),
      m_anim(1, 1, "placeholder.png",false, false)
{
    m_collider.setPosition(m_position);
    m_collider.setSize(m_size);
    m_collider.setOrigin(m_position.x/2, m_position.y/2);
    m_Sprite.setOrigin(m_position.x/2, m_position.y/2);
}

bool Gameobject::setTexture(std::string TexturePath) {
    return m_texture.loadFromFile(TexturePath);
}

void Gameobject::setVisible(bool visible) {
    isVisible = visible;
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
