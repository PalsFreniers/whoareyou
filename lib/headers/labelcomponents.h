#pragma once

#include "component.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>

class LabelComponent : public Component {
    LabelComponent(std::string text, std::string fontPath, int fontsize = 12, sf::Color textColor = sf::Color::White, sf::Vector2f textOffset = sf::Vector2f(0, 0));
    ~Label();

    void setFontSizem
}
