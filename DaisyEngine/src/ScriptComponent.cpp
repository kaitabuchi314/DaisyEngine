#include "ScriptComponent.h"

namespace Daisy
{
	void ScriptComponent::OnStart(ComponentManager* componentManager)
	{

	}

	void ScriptComponent::OnUpdate(ComponentManager* componentManager, float dt)
	{
		if (script != nullptr && EditorStates::IsPlaying())
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

		if (EditorStates::IsEditing())
		{
			frame = 0;
		}
	}

	void ScriptComponent::OnRender(ComponentManager* componentManager)
	{

	}

	void ScriptComponent::OnReset(ComponentManager* componentManager)
	{

	}

	void ScriptComponent::OnSave(ComponentManager* componentManager)
	{

	}
}
