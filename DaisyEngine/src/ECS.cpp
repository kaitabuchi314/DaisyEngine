#include "ECS.h"

namespace Daisy
{
    void SetActiveComponentManager(ComponentManager* componentManager)
    {
        activeComponentManager = componentManager;
    }

    ComponentManager* GetActiveComponentManager()
    {
        return activeComponentManager;
    }

    void ComponentSystem::update(ComponentManager& manager, float dt)
    {
        manager.updateComponents<TransformComponent>(dt);
        manager.updateComponents<SpriteComponent>(dt);
        manager.updateComponents<ScriptComponent>(dt);
    }

    void ComponentSystem::render(ComponentManager& manager)
    {
        manager.renderComponents<TransformComponent>();
        manager.renderComponents<SpriteComponent>();
        manager.renderComponents<ScriptComponent>();
    }

    void ComponentSystem::save(ComponentManager& manager)
    {
        manager.saveComponents<TransformComponent>();
        manager.saveComponents<SpriteComponent>();
        manager.saveComponents<ScriptComponent>();
    }

    void ComponentSystem::reset(ComponentManager& manager)
    {
        manager.resetComponents<TransformComponent>();
        manager.resetComponents<SpriteComponent>();
        manager.resetComponents<ScriptComponent>();
    }

    void ComponentSystem::addEntity(Entity entity)
    {
        entities.push_back(entity);
    }
}
