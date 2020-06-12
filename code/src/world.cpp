
#include "world.h"
#include "plane.h"
#include "airport.h"

namespace
{
    //------------------------------------------------|
    void LoadAirplaneTemplates(GameWorld &world)
    {
        PlaneStats c172("Cessna", "172");
        c172.cargoCapacity = 900;
        c172.cruisingAltitude = 7000;
        c172.engineCount = 1;
        c172.engineType = e_EnginePropulsionType::PROP;
        c172.fuelCapacity = 39;
        c172.wingspan = 36;
        c172.length = 27;
        c172.planeWeight = 1680;
        c172.requireRunwayLength = 1000;
        c172.passengerCapacity = 4;
        c172.maxSpeed = 140;

        world.m_planeTemplates.push_back(c172);
    }
    char getRandomRegCharacter(bool skipIandO = false)
    {
        char result = 'A';
        do
        {
            result = rand() % 25 + 'A';
        } while (skipIandO && (result == 'O' || result == 'I'));
        return result;
    }

    void LoadAirports(GameWorld &world)
    {
        AirportObject KRNT;
        KRNT.AIRPORTID = 0;
        KRNT.altitude = 32;
        KRNT.hasFuel = true;
        KRNT.runwayLength = 5300;
        sprintf_s(KRNT.ICAO, 5, "KRNT");
        world.m_airports.push_back(KRNT);

        for (int i = 0; i < 10; i++)
        {
            AirportObject newAirport;
            newAirport.AIRPORTID = i + 1;
            newAirport.altitude = static_cast<float>(rand() % 2000);
            newAirport.hasFuel = true;
            newAirport.runwayLength = (rand() % 3000) + 1500;
            sprintf_s(newAirport.ICAO, 5, "K%c%c%c", getRandomRegCharacter(), getRandomRegCharacter(), getRandomRegCharacter());

            world.m_airports.push_back(newAirport);
        }
    }

    void LoadPlanes(GameWorld &world)
    {
        const PlaneStats *stats = &world.m_planeTemplates[0];
        for (int i = 0; i < 20; i++)
        {
            PlaneObject newPlane;
            newPlane.stats = stats;
            newPlane.activeState = e_PlaneState::PARKED;
            newPlane.currentAirport = &world.m_airports[rand() % world.m_airports.size()];
            sprintf_s(newPlane.name, 7, "N%c%c%c%c%c",
                      rand() % 9 + '1',
                      rand() % 10 + '1',
                      rand() % 10 + '1',
                      getRandomRegCharacter(true),
                      getRandomRegCharacter(true));

            world.m_planes.push_back(newPlane);
        }
    }

} // namespace

void ClearGameWorld(GameWorld &world)
{
    world.m_airports.clear();
    world.m_planes.clear();
    world.m_planeTemplates.clear();
}

bool GameWorld::Generate()
{
    ClearGameWorld(*this);
    LoadAirplaneTemplates(*this);
    LoadAirports(*this);
    LoadPlanes(*this);
    return true;
}

void GameWorld::Update(double updateMs)
{
    m_timeSinceLastLog += updateMs;
    if (m_timeSinceLastLog > 6000)
    {
        m_timeSinceLastLog = 0;
        printf("PlaneUpdateGoesHere!\n");
        //Log plane info
        //Log Airport info
    }

    // Tick each plane

    // Tick each airport
}
