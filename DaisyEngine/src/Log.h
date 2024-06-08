#pragma once
#include <iostream>

namespace Daisy
{
	namespace Debug
	{
		inline bool loggingEnabled = true;

		void Log(const char* t);
		void LogError(const char* t);
		void LogWarning(const char* t);

		void SetLogsEnabled(bool logs);
	}
}