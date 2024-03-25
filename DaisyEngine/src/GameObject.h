#pragma once
#include <vector>
#include "Component.h"

namespace Daisy
{
	class GameObject
	{
	public:
		std::vector<Component*> components;

		void onStart();

		void addComponent(Component* c);
	};
}
