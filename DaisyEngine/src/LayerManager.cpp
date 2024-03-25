#pragma once
#include <vector>
#include <Layer.h>

namespace Daisy
{

	namespace LayerManager
	{
		std::vector<Layer*> layers;
		Layer* activeLayer;

		void PushLayer(Layer* layer)
		{
			layers.push_back(layer);
		}

		void Run()
		{
			if (activeLayer != nullptr)
			{
				activeLayer->Init();
				activeLayer->Run();
				activeLayer->Quit();
			}
			
		}
	}

}