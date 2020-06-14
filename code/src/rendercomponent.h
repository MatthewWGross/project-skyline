#pragma once
#include "gamecomponent.h"
#include <glm.hpp>

class RenderComponent : public IGameComponent
{ 
public:
    RenderComponent(GameObject* parent);
    ~RenderComponent() { }
protected:
    virtual void onParentDestroyed();
private:
    const glm::mat4* m_transform;
};