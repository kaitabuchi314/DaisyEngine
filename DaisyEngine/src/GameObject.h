#pragma once
#include <vector>
#include "Component.h"
#include <vec2.h>

namespace Daisy
{
	class GameObject
	{
	public:
		std::vector<Component*> components;
		vec2 position;
		vec2 scale;
		GameObject() : position(0,0), scale(0,0){};
		void onStart();
		void onUpdate();
		void onRender();
		void addComponent(Component* c);
	};
}
