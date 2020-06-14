
#include "world.h"
#include "gameobject.h"
#include "planecomponent.h"
#include "airportcomponent.h"
#include "rendercomponent.h"

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
        for (int i = 0; i < 10; i++)
        {
            GameObject *parent = new GameObject();
            AirportComponent *newAirport = new AirportComponent(parent);
            parent->m_components.push_back(newAirport);
            newAirport->AIRPORTID = i + 1;
            newAirport->altitude = static_cast<float>(rand() % 2000);
            newAirport->hasFuel = true;
            newAirport->runwayLength = (rand() % 3000) + 1500;
            sprintf_s(newAirport->ICAO, 5, "K%c%c%c", getRandomRegCharacter(), getRandomRegCharacter(), getRandomRegCharacter());

            world.m_airports.push_back(parent);
        }
    }

    void LoadPlanes(GameWorld &world)
    {
        const PlaneStats *stats = &world.m_planeTemplates[0];
        for (int i = 0; i < 20; i++)
        {
            GameObject *parent = new GameObject();
            PlaneComponent *newPlane = new PlaneComponent(parent);
            parent->m_components.push_back(newPlane);
            newPlane->stats = stats;
            newPlane->activeState = e_PlaneState::PARKED;
            newPlane->currentAirport = world.m_airports[rand() % world.m_airports.size()];
            sprintf_s(newPlane->name, 7, "N%c%c%c%c%c",
                      rand() % 9 + '1',
                      rand() % 10 + '1',
                      rand() % 10 + '1',
                      getRandomRegCharacter(true),
                      getRandomRegCharacter(true));


            RenderComponent* renderComp = new RenderComponent(parent);
            world.m_renderComponents.push_back(renderComp);
            parent->m_components.push_back(renderComp);

            float randx = ((rand() % 2000) * .01f) - 10.0f;
            float randy = 0.0f;
            float randz = ((rand() % 2000) * .01f) - 10.0f;
            parent->m_transform[3] = glm::vec4(randx, randy, randz, 1.0f);




            world.m_planes.push_back(parent);
        }
    }

} // namespace

GameWorld::~GameWorld()
{
    Reset();
}

void GameWorld::Reset()
{
    for each(GameObject * plane in m_planes)
       delete plane;
    
    for each(GameObject * airport in m_airports)
        delete airport;

    CleanupDeadRenderComponents();
    m_airports.clear();
    m_planes.clear();
    m_planeTemplates.clear();

    assert(m_renderComponents.size() == 0);
    m_renderComponents.clear();
}

bool GameWorld::Generate()
{
    Reset();
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
    CleanupDeadRenderComponents();
}

void GameWorld::CleanupDeadRenderComponents()
{
    size_t renderCount = m_renderComponents.size();
    for(size_t i = 0; i < renderCount; )
    {
        if(m_renderComponents[i]->GetParent() == nullptr)
        {
           delete m_renderComponents[i];
           m_renderComponents[i] = m_renderComponents[renderCount-1];
           renderCount--;
           m_renderComponents.pop_back();
        }
        else
        {
            i++;
        }
    }
}
