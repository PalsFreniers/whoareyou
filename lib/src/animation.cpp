

//I didn't use the constants from "Global.hpp" to make this class more universal.
#include <SFML/Graphics.hpp>
#include "../headers/animation.h"

Animation::Animation(Animation& other) 
    : animation_iterator(other.animation_iterator)
    , animation_speed(other.animation_speed)
    , current_frame(other.current_frame)
    , frame_width(other.frame_width)
    , total_frames(other.total_frames)
    , isPlaying(other.isPlaying)
    , position(other.position)
    , sprite(other.sprite)
    , texture(other.texture) {}

Animation::Animation(unsigned short i_animation_speed, unsigned short i_frame_width, const std::string& i_texture_location, bool play, bool loop) :
    animation_iterator(0),
    animation_speed(std::max<unsigned short>(1, i_animation_speed)),
    current_frame(0),
    frame_width(i_frame_width),
    isPlaying(play),
    isLoop(loop)
{
    texture.loadFromFile(i_texture_location);

    total_frames = texture.getSize().x / frame_width;
    sprite.setOrigin(sf::Vector2f((texture.getSize().x / total_frames) / 2, texture.getSize().y / 2));
    if(isLoop) animation_iterator = 1;
}

//This is for the enemies.
bool Animation::change_current_frame()
{
    current_frame++;

    if (current_frame == total_frames)
    {
	current_frame = 0;

	return 1;
    }

    return 0;
}

bool Animation::update()
{
    bool output = 0;
    animation_iterator++;
    while (animation_iterator >= animation_speed && isPlaying)
    {
	animation_iterator -= animation_speed;
	current_frame++;

	if (current_frame == total_frames)
	{
	    if(!isLoop) reset();
	    output = 1;
	    current_frame = 0;
	}
    }
    return output;
}

void Animation::play(sf::Vector2i pos, bool loop)
{
    reset();
    position.x =  pos.x; position.y =  pos.y;
    isLoop = loop;
    isPlaying = true;
    animation_iterator = 1;
}


void Animation::draw(sf::RenderWindow& i_window, const sf::Color& i_color)
{
    if(isPlaying) {
	//I added coloring for the explosions.
	sprite.setColor(i_color);
	sprite.setPosition(position);
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(current_frame * frame_width, 0, frame_width, texture.getSize().y));

	i_window.draw(sprite);
    }
}

void Animation::reset()
{
    isPlaying = false;
    isLoop = false;
    animation_iterator = 0;
    current_frame = 0;
}
