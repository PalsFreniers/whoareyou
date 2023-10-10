#pragma once

class Component;

#include "gameobject.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <string>

class Component {
public:
    Component(std::string name);
    ~Component();

    virtual void update(Gameobject& parent) = 0;
    virtual void draw(Gameobject& parent, sf::RenderWindow& window) = 0;
    virtual void onAttach(Gameobject& parent) = 0;

    inline std::string getName() {return m_name;}
    inline void setName(std::string name) {m_name = name;}

    inline bool isActive()   {return active;}
    inline void Activate()   {active = true;}
    inline void Deactivate() {active = false;}

protected:
    std::string m_name;
    bool active;
};
