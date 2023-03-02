#pragma once

#include "gameobjects.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>

class label : Gameobject
{
public:
    label(sf::Vector2f position, sf::Vector2f size, std::string name, sf::Vector2f textOffset, int point, std::string str = "", bool hasBackground = false, bool isAnimated = false, int animationSpeed = 0);
    
    void draw(sf::RenderWindow &app) override;
    
    void setText(std::string str);
    void setfont(std::string pathToFont);
    void setSize(int point);
    void setTextOffset(sf::Vector2f textOffset);

    std::string getTextString();
    sf::Text getText();
    sf::Font getFont();
    sf::Vector2f getVector();
    int getPoint(); 
private:
    sf::Vector2f m_textOffset;
    sf::Text m_text;
    sf::Font m_font;
    std::string m_textString;
    int m_point, m_animspeed;
    bool b_hasBackground;
};
