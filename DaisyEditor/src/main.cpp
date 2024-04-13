/* Daisy Game Engine Editor Version 0.1 */

#include <DaisyEditorLayer.h>

int main()
{
    DaisyEditorLayer* editorLayer = new DaisyEditorLayer();
    editorLayer->Run();

    delete editorLayer;
    return 0;
};

