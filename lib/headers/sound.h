#pragma once

#include <iostream>
#include <string>
#include <functional>
#include <SFML/Audio.hpp>
#include "signals.h"
#include "macros.h"

#define MAX_SOUND_NUMBER 255

static short soundNumber = 0;

class Sound {
    Sound();
    Sound(std::string pathToSound, bool isMusic, std::string name);
    ~Sound();

    void loadFromFile(std::string path);
    void play();
    void pause();
    void stop();
    void advance(sf::Time time);

    void setPlayEvent(std::function<void(Sound&)> event);
    void setPauseEvent(std::function<void(Sound&)> event);
    void setStopEvent(std::function<void(Sound&)> event);
    void setAdvanceEvent(std::function<void(Sound&, sf::Time)> event);
    
    std::function<void(Sound&)> getPlayEvent();
    std::function<void(Sound&)> getPauseEvent();
    std::function<void(Sound&)> getStopEvent();
    std::function<void(Sound&, sf::Time)> getAdvanceEvent();
    
    void setSignals(char signals);
    char getSignals();

    void setLoop();
    void setMusic();
    void setPlayEvent();
    void setPauseEvent();
    void setStopEvent();
    void setAdvanceEvent();
    
    void unsetLoop();
    void unsetMusic();
    void unsetPlayEvent();
    void unsetPauseEvent();
    void unsetStopEvent();
    void unsetAdvanceEvent();

    bool isLoop();
    bool isMusic();
    bool hasPlayEvent();
    bool hasPauseEvent();
    bool hasStopEvent();
    bool hasAdvanceEvent();

private:
    std::string m_name;
    char m_signals;
    sf::SoundBuffer m_buffer;
    sf::Sound m_sound;
    sf::Music m_music;

    std::function<void(Sound&)> onPlay;
    std::function<void(Sound&)> onPause;
    std::function<void(Sound&)> onStop;
    std::function<void(Sound&, sf::Time)> onAdvance;
};
