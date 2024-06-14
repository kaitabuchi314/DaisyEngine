#pragma once
#include <unordered_map>
#include <functional>

#include "Script.h"

namespace Petunia
{
	inline std::unordered_map<std::string, std::function<Script* ()>> scriptCreators;
}