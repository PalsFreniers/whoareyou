#include "../headers/sound.h"

Sound::Sound() {
    soundNumber++;
}
    
Sound::Sound(std::string pathToSound, bool isMusic, std::string name) : m_name(name) {
    if(soundNumber > MAX_SOUND_NUMBER) {
	ERROR("There is too much sound streaming could not create another");
	exit(1);
    }
    if(isMusic)	{
	setMusic();
	m_music.openFromFile(pathToSound);
    }
    else {
	m_buffer.loadFromFile(pathToSound);
	m_sound.setBuffer(m_buffer);
    }
    soundNumber++;
}

Sound::~Sound() {
    soundNumber--;
};

void Sound::loadFromFile(std::string path) {
    if(isMusic()) m_music.openFromFile(path);
    else {
	m_buffer.loadFromFile(path);
	m_sound.setBuffer(m_buffer);
    }
}

void Sound::play() {
    if(isMusic()) m_music.play();
    else m_sound.play();
}

void Sound::pause() {
    if(isMusic()) m_music.pause();
    else m_sound.pause();
}
    
void Sound::stop() {
    if(isMusic()) m_music.stop();
    else m_sound.stop();
}
void Sound::advance(sf::Time time) {
    if(isMusic()) m_music.setPlayingOffset(time);
    else m_sound.setPlayingOffset(time);
}

void Sound::setPlayEvent(std::function<void(Sound&)> event) {
    setPlayEvent();
    onPlay = event;
}

void Sound::setPauseEvent(std::function<void(Sound&)> event) {
    setPauseEvent();
    onPause = event;
}

void Sound::setStopEvent(std::function<void(Sound&)> event) {
    setStopEvent();
    onStop = event;
}

void Sound::setAdvanceEvent(std::function<void(Sound&, sf::Time)> event) {
    setAdvanceEvent();
    onAdvance = event;
}

std::function<void(Sound&)> Sound::getPlayEvent() {
    return onPlay;
}

std::function<void(Sound&)> Sound::getPauseEvent() {
    return onPause;
}

std::function<void(Sound&)> Sound::getStopEvent() {
    return onStop;
}

std::function<void(Sound&, sf::Time)> Sound::getAdvanceEvent() {
    return onAdvance;
}

void Sound::setSignals(char signals) {
    m_signals = signals;
}

char Sound::getSignals() {
    return m_signals;
}

void Sound::setLoop() {
    m_signals |= LOOP;
}

void Sound::setMusic() {
    m_signals |= MUSIC;
}

void Sound::setPlayEvent() {
    m_signals |= PLAY_EVENT;
}

void Sound::setPauseEvent() {
    m_signals |= PAUSE_EVENT;
}

void Sound::setStopEvent() {
    m_signals |= STOP_EVENT;
}

void Sound::setAdvanceEvent() {
    m_signals |= ADVANCE_EVENT;
}

void Sound::unsetLoop() {
    m_signals &= ~LOOP;
}

void Sound::unsetMusic() {
    m_signals &= ~MUSIC;
}

void Sound::unsetPlayEvent() {
    m_signals &= ~PLAY_EVENT;
}

void Sound::unsetPauseEvent() {
    m_signals &= ~PAUSE_EVENT;
}

void Sound::unsetStopEvent() {
    m_signals &= ~STOP_EVENT;
}

void Sound::unsetAdvanceEvent() {
    m_signals &= ~ADVANCE_EVENT;
}

bool Sound::isLoop() {
    return m_signals & LOOP;
}

bool Sound::isMusic() {
    return m_signals & MUSIC;
}

bool Sound::hasPlayEvent() {
    return m_signals & PLAY_EVENT;
}

bool Sound::hasPauseEvent() {
    return m_signals & PAUSE_EVENT;
}

bool Sound::hasStopEvent() {
    return m_signals & STOP_EVENT;
}

bool Sound::hasAdvanceEvent() {
    return m_signals & ADVANCE_EVENT;
}
