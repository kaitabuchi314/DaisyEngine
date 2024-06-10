#pragma once
#include <Entity.h>
#include <Renderer.h>
#include <ECS.h>
#include <Transform.h>

namespace Daisy
{
	class ComponentManager; // Forward declaration

	struct SpriteComponent
	{
		Texture image;
		Entity self;

		inline SpriteComponent(const Texture& img, Entity& e)
			: image(img), self(e) {}

		void OnStart(ComponentManager* componentManager);
		void OnUpdate(ComponentManager* componentManager, float dt);
		void OnRender(ComponentManager* componentManager);
	};
}