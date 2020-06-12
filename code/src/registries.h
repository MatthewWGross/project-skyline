#pragma once


//---------------------------------|
const char* PlaneRegistry_GetRegistration(unsigned int id);
unsigned int PlaneRegistry_CreateRegistration();
bool PlaneRegistry_SetRegistration(unsigned int id, const char* requestedID = nullptr); // must follow standard format if requested


// Registries to add: Pilot, Owner (Business/individual), Airport

