#pragma once
#include "gamecomponent.h"
#include <glm.hpp>

class RenderComponent : public IGameComponent
{ 
public:
    RenderComponent(GameObject* parent);
    ~RenderComponent() { }
    const glm::mat4* GetTransform();
protected:
    virtual void OnParentDestroyed() override;
private:
    const glm::mat4* m_transform;
};