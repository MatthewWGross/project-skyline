#pragma once

#include "gamecomponent.h"

enum class e_EnginePropulsionType
{
    PROP = 0,
    TURBINE,
    COUNT,
    INVALID
};

const unsigned int INVALID_PLANE_REGISTRATION = 0xFFFFFFFF;
const unsigned int INVALID_OWNER_ID = 0xFFFFFFFF;
const unsigned int INVALID_PILOT_ID = 0xFFFFFFFF;
struct PlaneStats
{
    PlaneStats(const char *planeMake, const char *planeModel)
    {
        make = planeMake;
        model = planeModel;
    }
    const char *make;
    const char *model;
    unsigned int engineCount = 0;
    e_EnginePropulsionType engineType = e_EnginePropulsionType::INVALID;
    float length = 0.0f;        // in ft
    float wingspan = 0.0f;      // in ft
    float cargoCapacity = 0.0f; // in lbs
    unsigned int passengerCapacity = 0;
    float planeWeight = 0.0f;         // TODO: calculate from components (in lbs)
    float fuelCapacity = 0.0f;        // in gallons
    float maxSpeed = 0.0f;            // in knots
    float requireRunwayLength = 0.0f; // in ft
    float cruisingAltitude = 0.0f;    // in ft
};

enum class e_PlaneState
{
    PARKED = 0,
    TAXIING,
    AIRBORNE,
    COUNT,
    INVALID
};
class GameObject;
class PlaneComponent : public IGameComponent
{
public:
    ~PlaneComponent(){}
    PlaneComponent(GameObject *parent) : IGameComponent(eGameComponentType::AIRPLANE, parent) {}
    const PlaneStats *stats = nullptr;
    float fuel = 0.0f;
    float altitude = 0.0f;
    e_PlaneState activeState = e_PlaneState::INVALID;
    const GameObject *currentAirport = nullptr; // only valid if parked
    unsigned int registrationID = INVALID_PLANE_REGISTRATION;
    char name[7] = {0}; // N100AA to N999ZZ format for now
    unsigned int ownerID = INVALID_OWNER_ID;
    unsigned int pilotID = INVALID_PILOT_ID;
};
