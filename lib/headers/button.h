#pragma once

#include <iostream>
#include <functional>
#include <string>
#include <SFML/Graphics.hpp>
#include "label.h"

class Button : public Label {
public:
    Button();
    Button(sf::Vector2f position, sf::Vector2f size, std::string name, std::string fontPath, int font_size = 12, std::string textString = "", sf::Vector2f textOffset = sf::Vector2f(0, 0), sf::Color textColor = sf::Color::White);
    ~Button();

    void tryClickEvent(sf::Vector2f MousePos);

    void setClickEvent(std::function<void(Button&)> onClickEvent);

    std::function<void(Button&)> getClickEvent();
    
    void setActive();
    void setClickEvent();

    void unsetActive();
    void unsetClickEvent();

    bool isActive();
    bool hasClickEvent();

private:
    std::function<void(Button&)> onClick;
};
