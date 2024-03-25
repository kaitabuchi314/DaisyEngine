#include "GameObject.h"

namespace Daisy
{
	void GameObject::onStart()
	{
		for (Component* c : components)
		{
			c->onStart(this);
		}
	}

	void GameObject::addComponent(Component* c)
	{
		components.push_back(c);
	}
}
