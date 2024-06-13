#include "Scene.h"

namespace Daisy
{
	Scene::Scene()
	{
		id = Daisy::Random::IntRandom(0, 4294967295);
	}

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

	bool HasSceneChanged()
	{
		return sceneChanged;
	}

	void ReceivedSceneChange()
	{
		sceneChanged = false;
	}

	void SetCurrentScene(Scene* scene)
	{
		currentScene = scene;
		sceneChanged = true;
	}

	Scene* GetActiveScene()
	{
		return currentScene;
	}
}

