#include "aclick.h"
#include "lib/headers/gameobjects.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/VideoMode.hpp>

using namespace sf;

Game g(600, 400, "test");

Gameobject g1(Vector2f(30, 30), Vector2f(20, 20), "TestObject");

Gameobject g2(Vector2f(100, 100), Vector2f(20, 20), "death");

Gameobject g3(Vector2f(300, 200), Vector2f(600, 400), "deathScreen");

void g1OnCollide(Gameobject& obj, Gameobject& other) {
    if (other.getName() == "death") {
        g3.setVisible(true);
        g.setPaused();
    }
}

void Game::init() {
    g1.setCollideEvent(g1OnCollide);
    g3.setVisible(false);
    g2.setRectangleColor(Color::Blue);
    g3.setRectangleColor(Color(255, 0, 0, 128));
    g1.setAnimation(Animation(8, 20, "placeholder.png", true, true));
}

void Game::event() {
    switch (m_event.type) {
        case Event::Closed:
            setClosed();
            break;
        case Event::KeyPressed:
            switch (m_event.key.code) {
                case Keyboard::Down:
                    if(!isPaused()) g1.move(Vector2f(0, 5));
                    break;
                case Keyboard::Up:
                    if(!isPaused()) g1.move(Vector2f(0, -5));
                    break;
                case Keyboard::Right:
                    if(!isPaused()) g1.move(Vector2f(5, 0));
                    break;
                case Keyboard::Left:
                    if(!isPaused()) g1.move(Vector2f(-5, 0));
                    break;
                case Keyboard::Space:
                    isPaused() ? unsetPaused() : setPaused();
                    break;
            }
    }
}

void Game::everUpdate() {
    ;
}

void Game::pauseUpdate() {
    g1.checkCollide(g2);
    g1.update();
}

void Game::draw() {
    g2.draw(m_window);
    g1.draw(m_window);
    g3.draw(m_window);
}

int main() {
    g.run();
    return 0;
}
