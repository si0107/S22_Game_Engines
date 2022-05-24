#pragma once
#include "PiguSprite.h"
#include "PiguShader.h"
#include "PiguRendererImplementation.h"
#include "PiguUtil.h"

namespace Pigu {
	
	class PIGU_API PiguRenderer
	{
	public:
		static void Init();
		static void Draw(Pigu::PiguSprite& picture, int xPos, int yPos, int zPos);
		static void ClearScreen();

	private:
		inline static PiguRenderer* mInstance{ nullptr };
		PiguRendererImplementation* mImplementation{ nullptr }; 
		PiguRenderer();
		Pigu::PiguShader mShader;
	};
}
