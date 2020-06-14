#pragma once
#include <vector>
class RenderComponent;
struct InputState;

namespace Platform
{
void InitPlatformAndWindow();
void UpdateInput(InputState& input);
void UpdateRender(const std::vector<RenderComponent*>& renderComponents);
void Shutdown();

void SetShouldShutdown();
bool ShouldShutdown();
double GetTime();
}