#pragma once

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include <functional>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include "../headers/animation.h"

class Gameobject {
public:
    Gameobject(sf::Vector2f position, sf::Vector2f size, std::string name);

    bool setTexture(std::string TexturePath);
    void setVisible(bool visible);

    void update();
    bool checkCollide(Gameobject& other);
    void draw(sf::RenderWindow window);
    void move(sf::Vector2f vel);

    // events
    void setCollideEvent(std::function<void(Gameobject&, Gameobject&)> onCollideEvent);
    void setDrawEvent(std::function<void(Gameobject&, sf::RenderWindow)> onDrawEvent);
    void setUpdateEvent(std::function<void(Gameobject&)> onUpdateEvent);
    void setMoveEvent(std::function<void(Gameobject&, sf::Vector2f)> onMove);
    
    void setRectangleColor(sf::Color c); 
    void setAnimation(Animation anim);

    inline sf::Vector2f getPosition() { return m_position; }
    inline sf::Vector2f getSize() { return m_size; }
protected:
    std::string m_name;
    sf::Vector2f m_position, m_size;
    sf::RectangleShape m_collider;
    sf::Texture m_texture;
    sf::Sprite m_Sprite;
    Animation m_anim;

    bool hasTexture, hasAnimation, isVisible, hasCollideEvent, hasDrawEvent, hasUpdateEvent, hasMoveEvent;
    
    std::function<void(Gameobject&)> onUpdate;
    std::function<void(Gameobject&, Gameobject&)> onCollide;
    std::function<void(Gameobject&, sf::RenderWindow)> onDraw;
    std::function<void(Gameobject&, sf::Vector2f)> onMove;
};
