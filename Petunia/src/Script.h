#pragma once

namespace Petunia
{
	class Script
	{
	public:
		virtual ~Script() {};
		virtual void OnStart(int self) {};
		virtual void OnUpdate(int self) {};
	};
}