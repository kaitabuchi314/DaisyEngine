#include "Transform.h"

namespace Daisy
{
    void TransformComponent::OnStart(ComponentManager* componentManager) {}
    void TransformComponent::OnUpdate(ComponentManager* componentManager, float dt) {}

    void TransformComponent::OnRender(ComponentManager* componentManager)
    {

    }

    void TransformComponent::Translate(glm::vec3 translation)
    {
        position += translation;
    }

    void TransformComponent::Scale(glm::vec3 scaleChange)
    {
        scale += scaleChange;
    }

    void TransformComponent::Rotate(glm::vec3 rotationChange)
    {
        rotation += rotationChange;
    }
}