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

	void GameObject::onUpdate()
	{
		for (Component* c : components)
		{
			c->onUpdate(this);
		}
	}
	void GameObject::onRender()
	{
		for (Component* c : components)
		{
			c->onRender(this);
		}
	}

	void GameObject::addComponent(Component* c)
	{
		components.push_back(c);
	}
}
