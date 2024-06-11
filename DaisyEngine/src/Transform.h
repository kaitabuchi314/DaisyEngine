#pragma once
#include "Entity.h"
#include <glm.hpp>
#include "ECS.h"
namespace Daisy
{
    class ComponentManager; // Forward declaration

    struct TransformComponent
    {
        glm::vec3 position;
        glm::vec3 scale;
        glm::vec3 rotation;
        Entity self;

        void OnStart(ComponentManager* componentManager);
        void OnUpdate(ComponentManager* componentManager, float dt);
        void OnRender(ComponentManager* componentManager);
        void Translate(glm::vec3 translation);
        void Scale(glm::vec3 scaleChange);
        void Rotate(glm::vec3 rotationChange);
    };
}


