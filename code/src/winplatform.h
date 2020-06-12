#pragma once

struct InputState;

namespace Platform
{
void InitPlatformAndWindow();
void UpdateInput(InputState& input);
void UpdateRender();
void Shutdown();

void SetShouldShutdown();
bool ShouldShutdown();
double GetTime();
}