#include "../headers/game.h"

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

void Game::run() {
    setVisible();
    setClosable();
    setResizable();
    init();
    while (isOpen()) {
        m_window.clear(m_background);
        while(m_window.pollEvent(m_event)) event();
        if(!isPaused()) pauseUpdate();
        everUpdate();
        draw();
        m_window.display();
    }
}

/////////Setters/////////

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
    m_signals = signals;
}

void Game::setBackground(sf::Color background) {
    m_background = background;
}

/////////////////////////

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
char Game::getSignals() {
    return m_signals;
}

//set function

void Game::setFullScreen() {
    m_signals |= FULLSCREEN;
    reloadWindow();
}

void Game::setVisible() {
    m_signals |= VISIBLE;
    reloadWindow();
}

void Game::setPaused() {
    m_signals |= PAUSED;
}

void Game::setClosable() {
    m_signals |= CLOSABLE;
    reloadWindow();
}

void Game::setResizable() {
    m_signals |= RESIZABLE;
    reloadWindow();
}

void Game::setClosed() {
    m_signals |= CLOSED;
    reloadWindow();
}

//unset functions

void Game::unsetFullscreen() {
    m_signals &= ~(FULLSCREEN);
    reloadWindow();
}

void Game::unsetVisible() {
    m_signals &= ~(VISIBLE);
    reloadWindow();
}

void Game::unsetPaused() {
    m_signals &= ~(PAUSED);
}

void Game::unsetClosable() {
    m_signals &= ~(CLOSABLE);
    reloadWindow();
}

void Game::unsetResizable() {
    m_signals &= ~(RESIZABLE);
    reloadWindow();
}

void Game::unsetClosed() {
    m_signals &= ~(CLOSED);
    reloadWindow();
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

void Game::reloadWindow() {
    sf::Uint32 style = sf::Style::None;
    if(isFullscreen()) style = sf::Style::Fullscreen;
    else style = (isClosable() ? sf::Style::Close : 0) | (isResizable() ? sf::Style::Resize : 0) | sf::Style::Titlebar;
    if(!isOpen()) m_window.close();
    else m_window.create(sf::VideoMode(m_size.x, m_size.y), m_title, style);
    m_window.setFramerateLimit(60);
    m_window.setVisible(isVisible());
}

