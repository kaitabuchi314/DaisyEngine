#pragma once
#include "Renderer2D.h"

namespace Daisy
{
	extern Renderer2D* activeRenderer;

	void ActivateRenderer(Renderer2D* renderer);

	Image LoadImage(std::string path);
	void DrawImage(Image tex, float x, float y, float scaleX, float scaleY);
}