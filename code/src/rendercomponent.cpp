#include "rendercomponent.h"
#include "gameobject.h"

RenderComponent::RenderComponent(GameObject* parent)
: IGameComponent(eGameComponentType::RENDER, parent)
{
    SetOwnedByParent(false); // these are owned by the render system
}

void RenderComponent::OnParentDestroyed()
{
    IGameComponent::OnParentDestroyed();
}

const glm::mat4* RenderComponent::GetTransform()
{
    if(GetParent())
    {
        return &GetParent()->m_transform;
    }
    else
    {
        return nullptr;
    }
    

}
