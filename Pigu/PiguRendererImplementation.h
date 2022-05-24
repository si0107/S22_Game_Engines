#pragma once

#include "PiguSprite.h"
#include "PiguShader.h"

namespace Pigu
{
	class PiguRendererImplementation
	{
	public:
		virtual void Draw(Pigu::PiguSprite& picture, int xPos, int yPos, int zPos, Pigu::PiguShader shader) = 0;
		virtual void ClearScreen() = 0;
	};
}
