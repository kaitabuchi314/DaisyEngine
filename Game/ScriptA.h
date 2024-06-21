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
			transformComponent->position.x += 0.0001f;
		else if (Daisy::KeyInput::GetKeyDown(DAISY_KEY_LEFT))
			transformComponent->position.x -= 0.0001f;
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