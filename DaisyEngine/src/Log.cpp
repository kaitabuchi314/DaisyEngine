#include "Log.h"

namespace Daisy
{
	void Debug::Log(const char* t)
	{
		if (loggingEnabled)
		{
			std::cout << t << std::endl;
		}
	}

	void Debug::LogError(const char* t)
	{
		std::cout << "Error: " << t << std::endl;
		std::exit(-1);
	}

	void Debug::LogWarning(const char* t)
	{
		if (loggingEnabled)
		{
			std::cout << "Warning: " << t << std::endl;
		}
	}

	void Debug::SetLogsEnabled(bool logs)
	{
		loggingEnabled = logs;
	}
}