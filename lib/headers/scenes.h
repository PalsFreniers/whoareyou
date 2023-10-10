#pragma once

#include "gameobject.h"
#include <SFML/Window/Event.hpp>
#include <vector>
class Scene {
public:
    Scene(int id, std::string name);
    ~Scene();

    Gameobject getObjectByName(std::string name);
    void run(
private:
    int m_id;
    std::string m_name;
    std::vector<Gameobject> m_ObjList;
};
