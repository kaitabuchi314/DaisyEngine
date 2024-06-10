#include "Entity.h"

namespace Daisy
{
    Entity CreateEntity()
    {
        return Random::IntRandom(0, 4294967295);
    }
}