#pragma once

class ScriptA : public Petunia::Script
{
public:
	virtual ~ScriptA() override {}

	virtual void OnStart(int self) override
	{
		componentManager = Daisy::GetActiveComponentManager();
		transformComponent = &componentManager->getComponent<Daisy::TransformComponent>((Daisy::Entity)self);
	}

	virtual void OnUpdate(int self) override
	{
		if (Daisy::KeyInput::GetKeyDown(DAISY_KEY_RIGHT))
		{
			transformComponent->position.x += 0.0003f;
			transformComponent->rotation.z += -0.1f;
		}
		else if (Daisy::KeyInput::GetKeyDown(DAISY_KEY_LEFT))
		{
			transformComponent->position.x -= 0.0003f;
			transformComponent->rotation.z -= -0.1f;
		}

		if (Daisy::KeyInput::GetKeyDown(DAISY_KEY_UP))
			transformComponent->position.y += 0.0003f;
		else if (Daisy::KeyInput::GetKeyDown(DAISY_KEY_DOWN))
			transformComponent->position.y -= 0.0003f;
		

		glm::vec3 cpos = lerp(Daisy::GetMainCamera()->cameraPos, transformComponent->position, 0.002f);
		Daisy::GetMainCamera()->cameraPos.x = cpos.x;
		Daisy::GetMainCamera()->cameraPos.y = cpos.y;
	}
private:
	glm::vec3 lerp(const glm::vec3& startPos, const glm::vec3& endPos, float t)
	{
		return startPos + t * (endPos - startPos);
	}
private:
	Daisy::TransformComponent* transformComponent;
	Daisy::ComponentManager* componentManager;
};

inline Petunia::Script* CreateScriptA()
{
	return new ScriptA();
}

/*
class ScriptA : public Petunia::Script
{
public:
	virtual ~ScriptA() override {}

	virtual void OnStart(int self) override
	{
		
	}

	virtual void OnUpdate(int self) override
	{
		
	}
};

inline Petunia::Script* CreateScriptA()
{
	return new ScriptA();
}
*/