#pragma once

#include "gamecomponent.h"

const unsigned int INVALID_AIRPORT_ID = 0xFFFFFFFF;

class AirportComponent : public IGameComponent
{
public:
    ~AirportComponent() {}

    AirportComponent::AirportComponent(GameObject *parent) : IGameComponent(eGameComponentType::AIRPORT, parent) {}
    bool hasFuel = true;
    // TODO: Available Cargo
    float xPos = 0.0f;
    float yPos = 0.0f;
    float altitude = 0.0f;

    unsigned int runwayLength = 0; // meters
    //TODO Add Runway System;
    unsigned int AIRPORTID = INVALID_AIRPORT_ID;
    char ICAO[5] = {0};
};