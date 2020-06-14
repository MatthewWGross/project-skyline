#pragma once
#include <vector>
#include "planeComponent.h"
class GameObject;
class RenderComponent;
class GameWorld
{
public:
    ~GameWorld();
    bool Generate();
    void Update(double updateMs);
    void Reset();
    void CleanupDeadRenderComponents();

    std::vector<GameObject *> m_planes;
    std::vector<GameObject *> m_airports;
    std::vector<PlaneStats> m_planeTemplates;
    std::vector<RenderComponent*> m_renderComponents;

    double m_timeSinceLastLog = 0;
    //TODO: Spatial partioning for objects and "GetNearby" functions
};
