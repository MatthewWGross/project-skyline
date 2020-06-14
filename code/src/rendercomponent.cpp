#include "rendercomponent.h"
#include "gameobject.h"

RenderComponent::RenderComponent(GameObject* parent)
: IGameComponent(eGameComponentType::RENDER, parent)
{
    m_transform = &parent->m_transform;
    SetOwnedByParent(false); // these are owned by the render system
}

void RenderComponent::onParentDestroyed()
{
    IGameComponent::onParentDestroyed();
    m_transform = nullptr;
}
