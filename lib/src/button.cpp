#include "../headers/button.h"

Button::Button()
    : Label()
{
    ;
}

Button::Button(sf::Vector2f position, sf::Vector2f size, std::string name, std::string fontPath, int font_size, std::string textString, sf::Vector2f textOffset, sf::Color textColor)
    : Label(position, size, name, fontPath, font_size, textString, textOffset, textColor)
{
    setActive();
    setBackground();
}

Button::~Button() {
    ;
}

bool Button::tryClickEvent(sf::Vector2f MousePos) {
    Gameobject tmp(MousePos, sf::Vector2f(2, 2), "Mouse Pointer");
    if(isActive() && hasClickEvent() && checkCollide(tmp)) {
	onClick(*this);
	return true;
    }
    return false;
}

void Button::setClickEvent(std::function<void(Button&)> onClickEvent) {
    onClick = onClickEvent;
    setClickEvent();
}

std::function<void(Button&)> Button::getClickEvent() {
    return onClick;
}

void Button::setActive() {
    m_signals |= ACTIVE | VISIBLE;
}

void Button::setClickEvent() {
    m_signals |= ON_CLICK_EVENT;
}

void Button::unsetActive() {
    m_signals &= ~(ACTIVE | VISIBLE);
}

void Button::unsetClickEvent() {
    m_signals &= ~(ON_CLICK_EVENT);
}

bool Button::isActive() {
    return m_signals & ACTIVE;
}

bool Button::hasClickEvent() {
    return m_signals & ON_CLICK_EVENT;
}
