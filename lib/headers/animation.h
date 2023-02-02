#pragma once

#include <SFML/Graphics.hpp>

class Animation
{
	//When this iterator reaches the animation speed, we change the frame and reset the iterator.
	unsigned short animation_iterator;
	//The higher the value, the slower the animation.
	unsigned short animation_speed;
	unsigned short current_frame;
	//To make things easier, each image file will contain 1 animation. So that the frame heights are the same.
	unsigned short frame_width;
	//We can find this by dividing the width of the image by the frame width.
	unsigned short total_frames;
    bool isPlaying;
    bool isLoop;
    
    sf::Vector2f position;

	sf::Sprite sprite;

	sf::Texture texture;
public:
	Animation(unsigned short i_animation_speed, unsigned short i_frame_width, const std::string& i_texture_location, bool play, bool loop = false);

	bool change_current_frame();
	bool update();
    void play(sf::Vector2i pos, bool loop);
    void setPosition(sf::Vector2f pos) { position.x = pos.x; position.y = pos.y; }

	void draw(sf::RenderWindow& i_window, const sf::Color& i_color = sf::Color(255, 255, 255));
	void reset();
};
