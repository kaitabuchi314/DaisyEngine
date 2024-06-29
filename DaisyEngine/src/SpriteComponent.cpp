#include "SpriteComponent.h"

namespace Daisy
{
	void SpriteComponent::OnStart(ComponentManager* componentManager) {};

	void SpriteComponent::OnUpdate(ComponentManager* componentManager, float dt) {};

	void SpriteComponent::OnRender(ComponentManager* componentManager)
	{
		TransformComponent* transformComponent = &componentManager->getComponent<TransformComponent>(self);
		Renderer2D::DrawImage(transformComponent->position, transformComponent->scale, transformComponent->rotation.z, &image, GetShaderProgram(), GetMainCamera());
	}

	void SpriteComponent::OnReset(ComponentManager* componentManager)
	{

	}

	void SpriteComponent::OnSave(ComponentManager* componentManager)
	{

	}
}