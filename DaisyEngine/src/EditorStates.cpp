#include "EditorStates.h"

namespace Daisy
{
	EditorState EditorStates::GetEditorState()
	{
		return editorState;
	}

	void EditorStates::SetEditorState(EditorState state)
	{
		editorState = state;
	}

	void EditorStates::EnterPlaymode()
	{
		editorState = EditorState::Play;
	}

	void EditorStates::ExitPlaymode()
	{
		editorState = EditorState::Edit;
	}

	bool EditorStates::IsPlaying()
	{
		return editorState == EditorState::Play;
	}

	bool EditorStates::IsEditing()
	{
		return editorState == EditorState::Edit;
	}
}