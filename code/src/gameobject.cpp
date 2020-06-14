#include "gameobject.h"
#include "gamecomponent.h"
GameObject::~GameObject()
{
    for each(IGameComponent * component in m_components)
        {
            component->onParentDestroyed();
            if(component->isOwnedByParent())
                delete component;
        }
}