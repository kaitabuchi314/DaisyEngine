#pragma once
#include "Component.h"
#include "Script.h"
#include <string>

namespace Daisy
{
	class ScriptComponent : public Component
	{
	public:
		std::string scriptName;
		virtual void onStart(GameObject* self) override
		{
			LoadScript();
			script->onStart(self);
		}
		virtual ~ScriptComponent() override
		{
			delete script;
		}
	private:
		Script* script;

		void LoadScript()
		{
			script = Scripts::LoadScript(scriptName)();
		}
	};
}
