#include "../headers/component.h"

Component::Component(std::string name) : m_name(name), active(true) {
}

Component::~Component() {
}
