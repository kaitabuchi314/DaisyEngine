#pragma once

namespace Daisy
{
	enum class EditorState
	{
		Edit, Play
	};

	namespace EditorStates
	{
		inline EditorState editorState;

		EditorState GetEditorState();
		void SetEditorState(EditorState state);

		void EnterPlaymode();
		void ExitPlaymode();

		bool IsPlaying();
		bool IsEditing();
	}
}