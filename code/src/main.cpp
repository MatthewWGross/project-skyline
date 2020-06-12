#include "winplatform.h"
#include "input.h"
#include "world.h"

int main(void)
{
	GameWorld world;
	world.Generate();

	InputState inputState;
	inputState.clear();

	Platform::InitPlatformAndWindow();
	double lastUpdateTime = Platform::GetTime();
	while (Platform::ShouldShutdown() == false)
	{
		Platform::UpdateInput(inputState);
		Platform::UpdateRender();
		double currentTime = Platform::GetTime();
		double msToUpdate = (Platform::GetTime() * 1000) - (lastUpdateTime * 1000); // todo: get update rate and place it here
		world.Update(msToUpdate);
		if (inputState.isKeyTriggered(KEY_ESCAPE))
		{
			Platform::SetShouldShutdown();
		}
		lastUpdateTime = currentTime;
	}
	return 0;
}