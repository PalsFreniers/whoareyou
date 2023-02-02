#include "aclick.h"
#include "lib/headers/gameobjects.h"
#include <SFML/System/Vector2.hpp>

using namespace sf;

Gameobject g1(Vector2f(30, 30), Vector2f(20, 20), "TestObject");

void Game::init() {
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
                    g1.move(Vector2f(0, 5));
            }
    }
}

void Game::everUpdate() {
    g1.update();
}

void Game::pauseUpdate() {
    ;
}

void Game::draw() {
    g1.draw(m_window);
}

int main() {
    Game g(600, 400, "test");
    g.run();
    return 0;
}
