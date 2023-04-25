#include "aclick.h"
#include "lib/headers/button.h"
#include "lib/headers/gameobject.h"
#include "lib/headers/label.h"
#include "lib/headers/player.h"
#include <SFML/Graphics/Color.hpp>

using namespace sf;

Player player(Vector2f(200, 200));
Button showHello(Vector2f(30, 30), Vector2f(60, 30), "showHelloButton", "font.otf", 12, "Show me");
Label helloLabel(Vector2f(30, 100), Vector2f(0, 0), "HelloLabel", "font.otf", 12, "Je suis un label");

void ShowHelloLabel(Button& b) {
    helloLabel.isVisible() ? helloLabel.unsetVisible() : helloLabel.setVisible();
}

void Game::init() {
    RectangleShape PlayerRectangle = player.getCollider();
    PlayerRectangle.setFillColor(Color::Blue);
    player.setRectangle(PlayerRectangle);
    player.setSpeed(1);
    showHello.setVisible();
    showHello.setActive();
    showHello.setHasCollision();
    showHello.setClickEvent(ShowHelloLabel);
    showHello.setTextColor(Color::Black);
    helloLabel.unsetVisible();
    helloLabel.setTextColor(Color::Blue);
}

void Game::event() {
    switch (m_event.type) {
        case Event::Closed:
            setClosed();
            break;
        case Event::MouseButtonPressed:
            {
                switch (m_event.mouseButton.button) {
                    case Mouse::Button::Left:
                        if(!showHello.tryClickEvent(Vector2f(Mouse::getPosition(m_window).x, Mouse::getPosition(m_window).y))) player.move(Vector2f(Mouse::getPosition(m_window).x, Mouse::getPosition(m_window).y));
                        break;
                    default:
                        break;
                }
                break;
            }
        case Event::KeyPressed:
            {
                switch (m_event.key.code) {
                    case Keyboard::P:
                        isPaused() ? unsetPaused() : setPaused();
                        break;
                    default:
                        break;
                }
                break;
            }
        default:
            break;
    } 
}

void Game::everUpdate() {
    ;
}

void Game::pauseUpdate() {
    player.update();
}

void Game::draw() {
    player.draw(m_window);
    showHello.draw(m_window);
    helloLabel.draw(m_window);
}

