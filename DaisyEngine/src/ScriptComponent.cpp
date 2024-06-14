#include "ScriptComponent.h"

namespace Daisy
{
	void ScriptComponent::OnStart(ComponentManager* componentManager)
	{

	}

	void ScriptComponent::OnUpdate(ComponentManager* componentManager, float dt)
	{
		if (script != nullptr)
		{
			if (frame == 0)
			{
				script->OnStart(self);
			}
			else
			{
				script->OnUpdate(self);
			}
			frame++;
		}
	}

	void ScriptComponent::OnRender(ComponentManager* componentManager)
	{

	}
}
