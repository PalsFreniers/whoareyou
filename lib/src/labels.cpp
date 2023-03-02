#include "../headers/labels.h"
#include <SFML/System/Vector2.hpp>

label::label(sf::Vector2f position, sf::Vector2f size, std::string name, sf::Vector2f textOffset, int point, bool hasBackground, bool isAnimated, int animationSpeed, std::string str) 
    : Gameobject(position, size, name)
    , m_textOffset(textOffset)
    , m_textString(str)
    , m_point(point)
    , m_animspeed(animationSpeed)
    , b_hasBackground(hasBackground)
{
    if(isAnimated) hasAnimation = true;
}

void label::draw(sf::RenderWindow &app) {
    if(hasDrawEvent) onDraw(*this, app);
    if(b_hasBackground) app.draw(m_collider);
    if(hasTexture) app.draw(m_Sprite);
    if(hasAnimation) m_anim.draw(app);
    app.draw(m_text);
}

void label::setText(std::string str) {
    m_textString = str;
    m_text.setString(m_textString);
}

void label::setfont(std::string pathToFont) {
    m_font.loadFromFile(pathToFont);
    m_text.setFont(m_font);
}

void label::setSize(int point) {
    m_point = point;
    m_text.setCharacterSize((96/72)*point);
}

void label::setTextOffset(sf::Vector2f textOffset) {
    m_textOffset = textOffset;
    m_text.setPosition(sf::Vector2f(m_textOffset.x + m_position.x, m_textOffset.y + m_position.y));
}
