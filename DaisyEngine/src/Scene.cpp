#include "Scene.h"

namespace Daisy
{
	void Scene::AddEntity(Entity entity)
	{
		entities.push_back(entity);
	}

	void Scene::RemoveEntity(int idx)
	{
		std::erase(entities, idx);
	}

	std::vector<Entity> Scene::GetEntities()
	{
		return entities;
	}

	bool Scene::HasEntity(Entity entity)
	{
		for (Entity e : entities)
		{
			if (e == entity)
			{
				return true;
			}
		}
		return false;
	}
	void SetCurrentScene(Scene* scene)
	{
		currentScene = scene;
	}

	Scene* GetActiveScene()
	{
		return currentScene;
	}
}

