#pragma once
#include "Entity.h"
#include "ECS.h"
#include <Petunia.h>

namespace Daisy
{
    class ComponentManager; // Forward declaration

    struct ScriptComponent
    {
        Petunia::Script* script;
        Entity self;
        char sname[64];
        int frame = 0;

        inline ScriptComponent(Petunia::Script* s, Entity m) : script(s), self(m) {};
        inline ~ScriptComponent() { delete script; };
        void OnStart(ComponentManager* componentManager);
        void OnUpdate(ComponentManager* componentManager, float dt);
        void OnRender(ComponentManager* componentManager);
    };
}


