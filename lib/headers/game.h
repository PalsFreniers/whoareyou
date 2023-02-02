#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
#include "signals.h"
/*
 * signals [0-7]:
 *   - fullscreen;
 *   - visible;
 *   - paused;
 *   - closable;
 *   - resizeable;
 *   - closed;
 *   - 
 *   - 
 */
class Game {
public:
    Game(int width, int height, std::string title, bool isFullscreen = false);
    ~Game();

    void init();
    void event();
    void everUpdate();
    void pauseUpdate();
    void draw();
    void run();

    //setters
    void setSize(int width, int height); void setSize(sf::Vector2u size);
    void setPosition(int x, int y); void setPosition(sf::Vector2i position);
    void setTitle(std::string title);
    void setSignal(char signals);

    //getters
    sf::Vector2u getSize();
    sf::Vector2i getPosition();
    std::string getTitle();

    //set functions
    void setFullScreen();
    void setVisible();
    void setPaused();
    void setClosable();
    void setResizable();
    void setClosed();

    //unset functions
    void unsetVisible();
    void unsetPaused();

    //is functions
    bool isFullscreen();
    bool isVisible();
    bool isPaused();
    bool isClosable();
    bool isResizable();
    bool isOpen();

private:
    sf::Vector2u m_size;
    sf::Vector2i m_position;
    std::string m_title;
    char m_signals;

    sf::RenderWindow m_window;
    sf::Event m_event;
    sf::Color m_background = sf::Color::Black;
};
