#include "../headers/labels.h"

Label::Label()
    : Gameobject()
    , m_fontSize(0)
    , m_textString("")
    , m_textOffset(sf::Vector2f(0, 0))
    , m_font()
    , m_text()
    , m_textColor(sf::Color::White)
 {
    m_text.setCharacterSize(m_fontSize);
    m_text.setString(m_textString);
    m_text.setOrigin(sf::Vector2f(m_size.x/2, m_size.y/2));
    m_text.setFillColor(m_textColor);
 }

Label::Label(sf::Vector2f position, sf::Vector2f size, std::string name, std::string fontPath, int font_size, std::string textString, sf::Vector2f textOffset, sf::Color textColor)
    : Gameobject(position, size, name)
    , m_fontSize(POINT_PIXEL_FACTOR * font_size)
    , m_textString(textString)
    , m_textOffset(textOffset)
    , m_font()
    , m_text()
    , m_textColor(textColor)
{
    m_font.loadFromFile(fontPath);
    m_text.setFont(m_font);
    m_text.setCharacterSize(m_fontSize);
    m_text.setString(m_textString);
    m_text.setOrigin(sf::Vector2f(m_size.x/2, m_size.y/2));
    m_text.setPosition(m_position + m_textOffset);
    m_text.setFillColor(m_textColor);
}

Label::~Label() {
    ;
}

void Label::draw(sf::RenderWindow &window) {
    if(!isVisible()) {
	return;
    }
    if(hasBackground()) {
	if(hasAnimation()) m_anim.draw(window);
        else if(hasTexture()) window.draw(m_Sprite);
	else window.draw(m_collider);
    }
    window.draw(m_text);
    if(hasDrawEvent()) onDraw(*this, window);
}

void Label::setFontSize(int point) {
    m_fontSize = POINT_PIXEL_FACTOR * point;
    m_text.setCharacterSize(m_fontSize);
}

void Label::setTextString(std::string textString) {
    m_textString = textString;
    m_text.setString(m_textString);
    if(hasTextStringChangeEvent()) onTextStringChange(*this, textString);
}

void Label::setTextOffset(sf::Vector2f textOffset) {
    m_textOffset = textOffset;
    m_text.setPosition(m_position + m_textOffset);
}

void Label::setFont(std::string fontPath) {
    m_font.loadFromFile(fontPath);
    m_text.setFont(m_font);
}

void Label::setFont(sf::Font font) {
    m_font = font;
    m_text.setFont(m_font);
}

void Label::setText(sf::Text text) {
    m_text = text;
    m_text.setPosition(m_position + m_textOffset);
    m_fontSize = m_text.getCharacterSize();
    m_textString = m_text.getString();
    m_font = *m_text.getFont();
}

void Label::setTextColor(sf::Color textColor) {
    m_textColor = textColor;
    m_text.setFillColor(textColor);
}

void Label::setTextStringChangeEvent(std::function<void(Label&, std::string)> onTextStringChangeEvent) {
    onTextStringChange = onTextStringChangeEvent;
    setTextStringChangeEvent();
}

int Label::getFontSize() {
    return m_fontSize * PIXEL_POINT_FACTOR;
}

std::string Label::getTextString() {
    return m_textString;
}

sf::Vector2f Label::getTextOffset() {
    return m_textOffset;
}

sf::Font Label::getFont() {
    return m_font;
}

sf::Text Label::getText() {
    return m_text;
}

sf::Color Label::getTextColor() {
    return m_textColor;
}

std::function<void(Label&, std::string)> Label::getTextStringChangeEvent() {
    return onTextStringChange;
}

void Label::setBackground() {
    m_signals |= BACKGROUND;
}

void Label::setTextStringChangeEvent() {
    m_signals |= TEXT_CHANGE_EVENT;
}

void Label::unsetBackground() {
    m_signals &= ~(BACKGROUND);
}

void Label::unsetTextStringChangeEvent() {
    m_signals &= ~(TEXT_CHANGE_EVENT);
}

bool Label::hasBackground() {
    return m_signals & BACKGROUND;
}

bool Label::hasTextStringChangeEvent() {
    return m_signals & TEXT_CHANGE_EVENT;
}

void Label::reloadLabel() {
    reloadGameobject();
    m_text.setCharacterSize(m_fontSize);
    m_text.setPosition(m_position + m_textOffset);
    m_text.setFillColor(m_textColor);
    m_text.setFont(m_font);
    m_text.setString(m_textString);
}
