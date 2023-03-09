#pragma once

#include <iostream>
#include <cstdint>
#include <string>
#include <functional>
#include <SFML/Graphics.hpp>
#include "signals.h"
#include "animation.h"

/* 
 * GameObject Signalsi [0-7]:
 *   - Texture;         0b00000001
 *   - Visible;         0b00000010
 *   - Animation;       0b00000100
 *   - Update Event;    0b00001000
 *   - Collide Event;   0b00010000
 *   - Draw Event;      0b00100000
 *   - Move Event;      0b01000000
 *   - 
 */

class Gameobject {
public:
    Gameobject();
    Gameobject(sf::Vector2f position, sf::Vector2f size, std::string name);
    ~Gameobject();
    
    virtual void update();
    virtual bool checkCollide(Gameobject& other);
    virtual void draw(sf::RenderWindow& window);
    virtual void move(sf::Vector2f vel);

    //setters
    void setName(std::string              name);
    void setPosition(sf::Vector2f         position);
    void setSize(sf::Vector2f             size);
    void setRectangle(sf::RectangleShape  collider);
    void setTexture(sf::Texture           texture);
    void setAnimation(Animation           animation);
    void setSignals(uint16_t              signals);

    void setUpdateEvent(std::function<void(Gameobject&)>                    onUpdateEvent);
    void setCollideEvent(std::function<void(Gameobject&, Gameobject&)>      onCollideEvent);
    void setDrawEvent(std::function<void(Gameobject&, sf::RenderWindow&)>   onDrawEvent);
    void setMoveEvent(std::function<void(Gameobject&, sf::Vector2f)>        onMoveEvent);

    //getters
    std::string        getName();
    sf::Vector2f       getPosition();
    sf::Vector2f       getSize();
    sf::RectangleShape getCollider();
    sf::Texture        getTexture();
    sf::Sprite         getSprite();
    Animation          getAnimation();
    uint16_t           getSignals();

    std::function<void(Gameobject&)>                      getUpdateEvent();
    std::function<void(Gameobject&, Gameobject&)>         getCollideEvent();
    std::function<void(Gameobject&, sf::RenderWindow&)>   getDrawEvent();
    std::function<void(Gameobject&, sf::Vector2f)>        getMoveEvent();

    //set
    void setTexture();
    void setVisible();
    void setAnimation();
    void setUpdateEvent();
    void setCollideEvent();
    void setDrawEvent();
    void setMoveEvent();

    //unset
    void unsetTexture();
    void unsetVisible();
    void unsetAnimation();
    void unsetUpdateEvent();
    void unsetCollideEvent();
    void unsetDrawEvent();
    void unsetMoveEvent();

    //has
    bool hasTexture();
    bool isVisible();
    bool hasAnimation();
    bool hasUpdateEvent();
    bool hasCollideEvent();
    bool hasDrawEvent();
    bool hasMoveEvent();

    void reloadGameobject();

protected:
    std::string          m_name;
    sf::Vector2f         m_position,
	                 m_size;
    sf::RectangleShape   m_collider;
    sf::Texture          m_texture;
    sf::Sprite           m_Sprite;
    Animation            m_anim;
    uint16_t             m_signals;
    
    std::function<void(Gameobject&)>                     onUpdate;
    std::function<void(Gameobject&, Gameobject&)>        onCollide;
    std::function<void(Gameobject&, sf::RenderWindow&)>  onDraw;
    std::function<void(Gameobject&, sf::Vector2f)>       onMove;
};
