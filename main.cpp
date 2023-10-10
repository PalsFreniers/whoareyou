#include "aclick.h"

void Game::init() {
    ;
}

void Game::event() {
    switch (m_event.type) {
        case sf::Event::Closed:
            setClosed();
            break;
        default:
            break;
    } 
}

void Game::everUpdate() {
    ;
}

void Game::pauseUpdate() {
    ;
}

void Game::draw() {
    ;
}

