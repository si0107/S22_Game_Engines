#include "pchPigu.h"
#include "PiguRenderer.h"
#include "GWindow.h"
#include "piguOpenGL/PiguOpenGLRenderer.h"

namespace Pigu 
{
	void PiguRenderer::Init()
	{
		if(mInstance == nullptr)
			mInstance = new PiguRenderer;
	}

	void PiguRenderer::Draw(Pigu::PiguSprite& picture, int xPos, int yPos, int zPos)
	{
		assert(mInstance != nullptr); //this makes it crash if we draw without initializing
		
		mInstance->mImplementation->Draw(picture, xPos, yPos, zPos, mInstance->mShader);
	}

	void PiguRenderer::ClearScreen()
	{
		mInstance->mImplementation->ClearScreen();
	}

	PiguRenderer::PiguRenderer() : 
		mShader("../Pigu/Assets/Shaders/defaultVertex.glsl", "../Pigu/Assets/Shaders/defaultFragment.glsl")
	{
#ifdef PIGU_OPENGL
		mImplementation = new PiguOpenGLRenderer;
#else
		#Only_OpenGL_is_supported_for_now
#endif

	}
}
