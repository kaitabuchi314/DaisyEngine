#include "ECS.h"
namespace Daisy
{
    template<typename T>
    void ComponentManager::addComponent(Entity entity, T component)
    {
        auto& bucket = getBucket<T>();
        bucket[entity] = std::make_shared<T>(component);
        bucket[entity]->OnStart(this); // Call OnStart when component is added
    }

    template<typename T>
    T& ComponentManager::getComponent(Entity entity)
    {
        auto& bucket = getBucket<T>();
        return *bucket.at(entity);
    }

    template<typename T>
    bool ComponentManager::hasComponent(Entity entity)
    {
        auto& bucket = getBucket<T>();
        return bucket.find(entity) != bucket.end();
    }

    template<typename T>
    void ComponentManager::updateComponents(float dt)
    {
        auto& bucket = getBucket<T>();
        for (auto& [entity, component] : bucket)
        {
            component->OnUpdate(this, dt); // Call OnUpdate for each component
        }
    }

    template<typename T>
    inline void ComponentManager::renderComponents()
    {
        auto& bucket = getBucket<T>();
        for (auto& [entity, component] : bucket)
        {
            component->OnRender(this); // Call OnUpdate for each component
        }
    }

    template<typename T>
    std::unordered_map<Entity, std::shared_ptr<T>>& ComponentManager::getBucket()
    {
        std::type_index index = std::type_index(typeid(T));
        if (components.find(index) == components.end())
        {
            components[index] = std::unordered_map<Entity, std::shared_ptr<void>>();
        }
        return *reinterpret_cast<std::unordered_map<Entity, std::shared_ptr<T>>*>(&components[index]);
    }
}
