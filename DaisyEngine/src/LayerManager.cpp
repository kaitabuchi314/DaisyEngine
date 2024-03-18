#pragma once
#include <vector>
#include <Layer.h>

namespace Daisy
{

	namespace LayerManager
	{
		std::vector<Layer*> layers;
		int activeLayer = -1;

		void PushLayer(Layer* layer)
		{
			layers.push_back(layer);
		}

		void Run()
		{
			Layer* layer = nullptr;
			for (Layer* l : layers)
			{
				if (l->id == activeLayer)
				{
					layer = l;
				}
			}

			if (layer != nullptr)
			{
				layer->Init();
				layer->Run();
				layer->Quit();
			}
			
		}
	}

}