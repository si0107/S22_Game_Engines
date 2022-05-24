#pragma once

#include "PiguRendererImplementation.h"

namespace Pigu
{
	class PiguOpenGLRenderer : public PiguRendererImplementation
	{
	public:
		virtual void Draw(Pigu::PiguSprite& picture, int xPos, int yPos, int zPos, Pigu::PiguShader shader) override;
		virtual void ClearScreen() override;

	};
}
