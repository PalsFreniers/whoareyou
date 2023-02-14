#pragma once

#include "gameobjects.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>

class label : Gameobject
{
public:
    label(sf::Vector2f position, sf::Vector2f size, std::string name, sf::Vector2f textOffset, int point, bool hasBackground = false, bool isAnimated = false, int animationSpeed = 0);
    void draw(sf::RenderWindow &app) override;
private:
    sf::Vector2f m_textOffset;
    sf::Text m_text;
    sf::Font m_font;
};
