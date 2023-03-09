#include "../headers/gameobject.h"

Gameobject::Gameobject()
    : m_name("")
    , m_position(sf::Vector2f(0, 0))
    , m_size(sf::Vector2f(0, 0))
    , m_collider(sf::Vector2f(0, 0))
    , m_texture()
    , m_Sprite(m_texture)
    , m_anim(0, 1, "placeholder.png", false)
    , m_signals(0)
{
    m_collider.setOrigin(sf::Vector2f(m_size.x / 2, m_size.y / 2));
    m_Sprite.setOrigin(sf::Vector2f(m_size.x / 2, m_size.y / 2));
}

Gameobject::Gameobject(sf::Vector2f position, sf::Vector2f size, std::string name)
    : m_name(name)
    , m_position(position)
    , m_size(size)
    , m_collider(size)
    , m_texture()
    , m_Sprite(m_texture)
    , m_anim(0, 1, "placeholder.png", false)
    , m_signals(VISIBLE)
{
    m_collider.setOrigin(sf::Vector2f(m_size.x / 2, m_size.y / 2));
    m_Sprite.setOrigin(sf::Vector2f(m_size.x / 2, m_size.y / 2));
}

Gameobject::~Gameobject() {
    ;
}

void Gameobject::update() {
    if(hasCollideEvent()) onUpdate(*this);
}

bool Gameobject::checkCollide(Gameobject &other) {
    if (m_position.x + m_size.x/2 < other.getPosition().x - other.getSize().x/2) return 0;
    if (m_position.x - m_size.x/2 > other.getPosition().x + other.getSize().x/2) return 0;
    if (m_position.y + m_size.y/2 < other.getPosition().y - other.getSize().y/2) return 0;
    if (m_position.y - m_size.y/2 > other.getPosition().y + other.getSize().y/2) return 0;
    if (hasCollideEvent()) onCollide(*this, other);
    return 1;
}

void Gameobject::draw(sf::RenderWindow &window) {
    if(!isVisible()) {
	return;
    }
    if(hasAnimation()) m_anim.draw(window);
    else if(hasTexture()) window.draw(m_Sprite);
    else window.draw(m_collider);
    if(hasDrawEvent()) onDraw(*this, window);
}

void Gameobject::move(sf::Vector2f vel) {
    m_position += vel;
    m_collider.setPosition(m_position);
    m_Sprite.setPosition(m_position);
    m_anim.setPosition(m_position);
    if(hasMoveEvent()) onMove(*this, vel);
}

void Gameobject::setName(std::string name) {
    m_name = name;
}

void Gameobject::setPosition(sf::Vector2f position) {
    m_position = position;
    m_collider.setPosition(m_position);
    m_Sprite.setPosition(m_position);
    m_anim.setPosition(m_position);
}

void Gameobject::setSize(sf::Vector2f size) {
    m_size = size;
    m_collider.setSize(m_size);
}

void Gameobject::setRectangle(sf::RectangleShape collider) {
    m_collider = collider;
    m_collider.setOrigin(sf::Vector2f(m_position.x/2, m_position.y/2));
    setPosition(m_collider.getPosition());
    setSize(m_collider.getSize());
}

void Gameobject::setTexture(sf::Texture texture) {
    m_texture = texture;
    m_Sprite.setTexture(texture);
    setTexture();
}

void Gameobject::setAnimation(Animation animation) {
    m_anim = animation;
    m_anim.setPosition(m_position);
    setAnimation();
}

void Gameobject::setSignals(uint16_t signals) {
    m_signals = signals;
}

void Gameobject::setUpdateEvent(std::function<void(Gameobject&)> onUpdateEvent) {
    onUpdate = onUpdateEvent;
    setUpdateEvent();
}

void Gameobject::setCollideEvent(std::function<void(Gameobject&, Gameobject&)> onCollideEvent) {
    onCollide = onCollideEvent;
    setCollideEvent();
}

void Gameobject::setDrawEvent(std::function<void(Gameobject&, sf::RenderWindow&)> onDrawEvent) {
    onDraw = onDrawEvent;
    setDrawEvent();
}

void Gameobject::setMoveEvent(std::function<void(Gameobject&, sf::Vector2f)> onMoveEvent) {
    onMove = onMoveEvent;
    setMoveEvent();
}

std::string Gameobject::getName() {
    return m_name;
}

sf::Vector2f Gameobject::getPosition() {
    return m_position;
}

sf::Vector2f Gameobject::getSize() {
    return m_size;
}

sf::RectangleShape Gameobject::getCollider() {
    return m_collider;
}

sf::Texture Gameobject::getTexture() {
    return m_texture;
}

sf::Sprite Gameobject::getSprite() {
    return m_Sprite;
}

Animation Gameobject::getAnimation() {
    return m_anim;
}

uint16_t Gameobject::getSignals() {
    return m_signals;
}

std::function<void(Gameobject&)> Gameobject::getUpdateEvent() {
    return onUpdate;
}

std::function<void(Gameobject&, Gameobject&)> Gameobject::getCollideEvent() {
    return onCollide;
}

std::function<void(Gameobject&, sf::RenderWindow&)> Gameobject::getDrawEvent() {
    return onDraw;
}

std::function<void(Gameobject&, sf::Vector2f)> Gameobject::getMoveEvent() {
    return onMove;
}

void Gameobject::setTexture() {
    m_signals |= TEXTURE;
}

void Gameobject::setVisible() {
    m_signals |= VISIBLE;
}

void Gameobject::setAnimation() {
    m_signals |= ANIMATION;
}

void Gameobject::setUpdateEvent() {
    m_signals |= UPDATE_EVENT;
}

void Gameobject::setCollideEvent() {
    m_signals |= COLLIDE_EVENT;
}

void Gameobject::setDrawEvent() {
    m_signals |= DRAW_EVENT;
}

void Gameobject::setMoveEvent() {
    m_signals |= MOVE_EVENT;
}

void Gameobject::unsetTexture() {
    m_signals &= ~(TEXTURE);
}

void Gameobject::unsetVisible() {
    m_signals &= ~(VISIBLE);
}

void Gameobject::unsetAnimation() {
    m_signals &= ~(ANIMATION);
}

void Gameobject::unsetUpdateEvent() {
    m_signals &= ~(UPDATE_EVENT);
}

void Gameobject::unsetCollideEvent() {
    m_signals &= ~(COLLIDE_EVENT);
}

void Gameobject::unsetDrawEvent() {
    m_signals &= ~(DRAW_EVENT);
}

void Gameobject::unsetMoveEvent() {
    m_signals &= ~(MOVE_EVENT);
}

bool Gameobject::hasTexture() {
    return m_signals & TEXTURE;
}

bool Gameobject::isVisible() {
    return m_signals & VISIBLE;
}

bool Gameobject::hasAnimation() {
    return m_signals & ANIMATION;
}

bool Gameobject::hasUpdateEvent() {
    return m_signals & UPDATE_EVENT;
}

bool Gameobject::hasCollideEvent() {
    return m_signals & COLLIDE_EVENT;
}

bool Gameobject::hasDrawEvent() {
    return m_signals & DRAW_EVENT;
}

bool Gameobject::hasMoveEvent() {
    return m_signals & MOVE_EVENT;
}

void Gameobject::reloadGameobject() {
    m_collider.setPosition(m_position);
    m_collider.setSize(m_size);
    m_Sprite.setTexture(m_texture);
    m_Sprite.setPosition(m_position);
    m_anim.setPosition(m_position);
}
