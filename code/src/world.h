#pragma once
#include <vector>

#include "plane.h"
#include "airport.h"

class GameWorld
{
public:
    bool Generate();
    void Update(double updateMs);

    std::vector<PlaneObject> m_planes;
    std::vector<AirportObject> m_airports;
    std::vector<PlaneStats> m_planeTemplates;

    double m_timeSinceLastLog = 0;
    //TODO: Spatial partioning for objects and "GetNearby" functions
};
