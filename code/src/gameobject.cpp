#include "gameobject.h"
#include "gamecomponent.h"
GameObject::~GameObject()
{
    for each(IGameComponent * component in m_components)
        {
            component->OnParentDestroyed();
            if(component->IsOwnedByParent())
                delete component;
        }
}