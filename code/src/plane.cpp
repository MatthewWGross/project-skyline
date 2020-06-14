#include "plane.h"
#include "physicsdata.h"
PlaneObject::~PlaneObject()
{
    if(m_physicsData != nullptr)
        delete m_physicsData;
}