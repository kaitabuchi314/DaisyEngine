#pragma once
#include <vector>
#include <Layer.h>
namespace Daisy
{
	namespace LayerManager
	{
		extern std::vector<Layer*> layers;
		extern Layer* activeLayer;

		void PushLayer(Layer* layer);
		void Run();
	}
}