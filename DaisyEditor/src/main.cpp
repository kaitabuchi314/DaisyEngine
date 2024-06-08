/* Daisy Game Engine Editor Version 0.1 */

#include <DaisyEditorLayer.h>

int main()
{
#ifdef DIST
    Daisy::Debug::SetLogsEnabled(false);
#endif
    DaisyEditorLayer editorLayer = DaisyEditorLayer();
    editorLayer.Run();

    return 0;
};