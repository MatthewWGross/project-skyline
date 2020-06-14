#pragma once
#include <glm.hpp>
#include <vector>

class IGameComponent;
class GameObject
{
public:
    ~GameObject();
    // array of components based on type
    std::vector<IGameComponent *> m_components;
    // transform
    glm::mat4 m_transform;
};