#include "ECS.h"

namespace Daisy
{


    void ComponentSystem::update(ComponentManager& manager, float dt)
    {
        manager.updateComponents<TransformComponent>(dt);
        manager.updateComponents<SpriteComponent>(dt);
    }

    void ComponentSystem::render(ComponentManager& manager)
    {
        manager.renderComponents<TransformComponent>();
        manager.renderComponents<SpriteComponent>();
    }

    void ComponentSystem::addEntity(Entity entity)
    {
        entities.push_back(entity);
    }
}
