#pragma once

namespace Daisy
{
	class GameObject;

	class Component
	{
	public:
		virtual ~Component() {};
		virtual void onStart(GameObject* self) {};
	};
}
