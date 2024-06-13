#pragma once
#include <Entity.h>
#include <vector>
#include <functional>

namespace Daisy
{
	class Scene
	{
	public:
		Scene();
		void AddEntity(Entity entity);
		void RemoveEntity(int idx);

		std::vector<Entity> GetEntities();
		bool HasEntity(Entity entity);
	public:
		int id;
	private:
		std::vector<Entity> entities;
	};

	inline Scene* currentScene;
	inline bool sceneChanged = false;

	bool HasSceneChanged();
	void ReceivedSceneChange();
	void SetCurrentScene(Scene* scene);
	Scene* GetActiveScene();
}