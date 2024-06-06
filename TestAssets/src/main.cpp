#include <SandboxLayer.h>

int main()
{
    SandboxLayer* sandboxLayer = new SandboxLayer();
    sandboxLayer->Run();

    delete sandboxLayer;
    return 0;
};

