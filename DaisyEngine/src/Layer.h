#pragma once

namespace Daisy
{
	class Layer
	{
	public:
		int id;
		virtual void Init() {};
		virtual void Run() {};
		virtual void Quit() {};
	};
}