#pragma once
#include <functional>
#include <string>
#include <map>

namespace Daisy
{
	class Script
	{
	public:
		virtual void onStart(GameObject* self) {};
	};
	namespace Scripts
	{
		std::map<std::string, std::function<Script* ()>> scripts;
		std::function<Script* ()> LoadScript(std::string name)
		{
			return scripts[name];
		}
	}
}
