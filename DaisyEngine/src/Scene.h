#pragma once
#include <Entity.h>
#include <vector>

namespace Daisy
{
	class Scene
	{
	public:
		void AddEntity(Entity entity);
		void RemoveEntity(int idx);

		std::vector<Entity> GetEntities();
		bool HasEntity(Entity entity);
	private:
		std::vector<Entity> entities;
	};

	inline Scene* currentScene;
	void SetCurrentScene(Scene* scene);
	Scene* GetActiveScene();
}