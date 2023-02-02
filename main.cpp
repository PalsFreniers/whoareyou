#include "aclick.h"
#include "lib/headers/gameobjects.h"
#include <SFML/System/Vector2.hpp>

using namespace sf;

Gameobject g1(Vector2f(30, 30), Vector2f(20, 20), "TestObject");

void g1OnUpdate(Gameobject& obj) {
    obj.move(Vector2f(1, 0));
}

void Game::init() {
    g1.setUpdateEvent(g1OnUpdate);
    g1.setRectangleColor(Color::Blue);
}

void Game::event() {
    ;
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
