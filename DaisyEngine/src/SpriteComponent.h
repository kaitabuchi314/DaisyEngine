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
		char path[128];
		
		Entity self;

		inline SpriteComponent(const Texture& img, Entity& e)
			: image(img), self(e), path() {}

		void OnStart(ComponentManager* componentManager);
		void OnUpdate(ComponentManager* componentManager, float dt);
		void OnRender(ComponentManager* componentManager);
		void OnReset(ComponentManager* componentManager);
		void OnSave(ComponentManager* componentManager);
	};
}