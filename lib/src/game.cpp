#include "../headers/game.h"
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>

Game::Game(int width, int height, std::string title, bool isFullscreen)
    : m_size(width, height),
      m_position(0, 0),
      m_title(title),
      m_signals(0)
{
    if(isFullscreen) setFullScreen();
    m_window.create(sf::VideoMode(width, height), title, (isFullscreen ? sf::Style::Fullscreen : sf::Style::Default));
}

Game::~Game() {
    m_window.close();
}

//setters

void Game::setSize(int width, int height) {
    m_size = sf::Vector2u(width, height);
    m_window.setSize(m_size);
}

void Game::setSize(sf::Vector2u size) {
    m_size = size;
    m_window.setSize(m_size);
}

void Game::setPosition(int x, int y) {
    m_position = sf::Vector2i(x, y);
    m_window.setPosition(m_position);
}

void Game::setPosition(sf::Vector2i position) {
    m_position = position;
    m_window.setPosition(m_position);
}

void Game::setTitle(std::string title) {
    m_title = title;
    m_window.setTitle(m_title);
}

void Game::setSignal(char signals) {
    m_signals |= signals;
}

//getters

sf::Vector2u Game::getSize() {
    return m_size;
}

sf::Vector2i Game::getPosition() {
    return m_position;
}

std::string Game::getTitle() {
    return m_title;
}

//set function

void Game::setFullScreen() {
    (&m_window)->create(sf::VideoMode(m_window.getSize().x, m_window.getSize().y), m_title, sf::Style::Fullscreen);
    m_signals |= FULLSCREEN;
}

void Game::setVisible() {
    m_signals |= VISIBLE;
}

void Game::setPaused() {
    m_signals |= PAUSED;
}

void Game::setClosable() {
    m_signals |= CLOSABLE;
}

void Game::setResizable() {
    m_signals |= RESIZABLE;
}

void Game::setClosed() {
    m_signals |= CLOSED;
}

//unset functions

void Game::unsetVisible() {
    m_signals &= ~(VISIBLE);
}

void Game::unsetPaused() {
    m_signals &= ~(PAUSED);
}

void Game::unsetFullscreen() {
    (&m_window)->create(sf::VideoMode(m_window.getSize().x, m_window.getSize().y), m_title, sf::Style::Fullscreen);
    m_signals &= ~(FULLSCREEN);
}

//is functions

bool Game::isFullscreen() {
    return m_signals & FULLSCREEN;
}

bool Game::isVisible() {
    return m_signals & VISIBLE;
}

bool Game::isPaused() {
    return m_signals & PAUSED;
}

bool Game::isClosable() {
    return m_signals & CLOSABLE;
}

bool Game::isResizable() {
    return m_signals & RESIZABLE;
}
bool Game::isOpen() {
    return !(m_signals & CLOSED);
}

void Game::run() {
    init();
    m_window.setFramerateLimit(60);
    while (isOpen()) {
        while(m_window.pollEvent(m_event)) event();
        m_window.clear(m_background);
        everUpdate();
        if(!isPaused()) pauseUpdate();
        draw();
        m_window.display();
    }
}
