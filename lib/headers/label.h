#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <functional>
#include <string>
#include "gameobject.h"

#define POINT_PIXEL_FACTOR 1.33 
#define PIXEL_POINT_FACTOR 0.75

class Label : public Gameobject {
public:
    Label();
    Label(sf::Vector2f position, sf::Vector2f size, std::string name, std::string fontPath, int font_size = 12, std::string textString = "", sf::Vector2f textOffset = sf::Vector2f(0, 0), sf::Color textColor = sf::Color::White);
    ~Label();

    void draw(sf::RenderWindow& window) override;
    
    void setFontSize(int            point);
    void setTextString(std::string  textString);
    void setTextOffset(sf::Vector2f textOffset);
    void setFont(std::string        fontPath);
    void setFont(sf::Font           font);
    void setText(sf::Text           text);
    void setTextColor(sf::Color     textColor);

    void setTextStringChangeEvent(std::function<void(Label&, std::string)> onTextStringChangeEvent);

    int		 getFontSize();
    std::string  getTextString();
    sf::Vector2f getTextOffset();
    sf::Font     getFont();
    sf::Text     getText();
    sf::Color    getTextColor();

    std::function<void(Label&, std::string)> getTextStringChangeEvent();

    void setBackground();
    void setTextStringChangeEvent();

    void unsetBackground();
    void unsetTextStringChangeEvent();

    bool hasBackground();
    bool hasTextStringChangeEvent();

    void reloadLabel();

protected:
    int		 m_fontSize;
    std::string  m_textString;
    sf::Vector2f m_textOffset;
    sf::Font     m_font;
    sf::Text     m_text;
    sf::Color    m_textColor;
    
    std::function<void(Label&, std::string)> onTextStringChange;
};
