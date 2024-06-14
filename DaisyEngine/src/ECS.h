#pragma once
#include "Scene.h"
#include <unordered_map>
#include <vector>
#include <typeindex>
#include <memory>
#include "Entity.h"
#include "Random.h"
#include "Transform.h"
#include "SpriteComponent.h"
#include "ScriptComponent.h"
#include <algorithm>

namespace Daisy
{


    class ComponentManager
    {
    public:
        template<typename T>
        T& getComponent(Entity entity);

        template<typename T>
        bool hasComponent(Entity entity);

        template<typename T>
        void updateComponents(float dt);

        template<typename T>
        void renderComponents();

        template<typename T>
        void addComponent(Entity entity, T component);

    private:
        std::unordered_map<std::type_index, std::unordered_map<Entity, std::shared_ptr<void>>> components;

        template<typename T>
        std::unordered_map<Entity, std::shared_ptr<T>>& getBucket();
    };

    inline ComponentManager* activeComponentManager;
    void SetActiveComponentManager(ComponentManager* componentManager);
    ComponentManager* GetActiveComponentManager();

    class ComponentSystem
    {
    public:
        void update(ComponentManager& manager, float dt);
        void render(ComponentManager& manager);

        void addEntity(Entity entity);

    private:
        std::vector<Entity> entities;
    };
}

#include "ECS.inl"