#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
#include "signals.h"

/*
 * signals [0-7]:
 *   - fullscreen;   0b00000001
 *   - visible;      0b00000010
 *   - paused;       0b00000100
 *   - closable;     0b00001000
 *   - resizeable;   0b00010000
 *   - closed;       0b00100000
 *   - 
 *   - 
 */

class Game {
public:
    Game(int width, int height, std::string title, bool isFullscreen = false);
    ~Game();

    void run();

    /////////Code Defined functions/////////
    void init();
    void event();
    void everUpdate();
    void pauseUpdate();
    void draw();
    ////////////////////////////////////////

    /////////Setters/////////
    void setSize(int width, int height); void setSize(sf::Vector2u size);
    void setPosition(int x, int y); void setPosition(sf::Vector2i position);
    void setTitle(std::string title);
    void setSignal(char signals);
    /////////////////////////

    /////////Getters/////////
    sf::Vector2u getSize();
    sf::Vector2i getPosition();
    std::string getTitle();
    char getSignals();
    /////////////////////////

    /////////Set Signal Function/////////
    void setFullScreen();
    void setVisible();
    void setPaused();
    void setClosable();
    void setResizable();
    void setClosed();
    /////////////////////////////////////

    /////////Unset Signal Function/////////
    void unsetFullscreen();
    void unsetVisible();
    void unsetPaused();
    void unsetClosable();
    void unsetResizable();
    void unsetClosed();
    ///////////////////////////////////////

    /////////Is Signal Function/////////
    bool isFullscreen();
    bool isVisible();
    bool isPaused();
    bool isClosable();
    bool isResizable();
    bool isOpen();
    ////////////////////////////////////

private:
    sf::Vector2u m_size;
    sf::Vector2i m_position;
    std::string m_title;
    char m_signals;

    sf::RenderWindow m_window;
    sf::Event m_event;
    sf::Color m_background = sf::Color::Black;
};
