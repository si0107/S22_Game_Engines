#include "pchPigu.h"
#include "PiguSprite.h"
#include "piguOpenGL/PiguOpenGLSprite.h" //specificOpenGL

namespace Pigu
{
	PiguSprite::PiguSprite(const std::string& filename)
	{
#ifdef PIGU_OPENGL
		mImplementation = new PiguOpenGLSprite{ filename };
#else
		#Only_OpenGL_is_supported_for_now
#endif
	}

	int PiguSprite::GetWidth() const
	{
		return mImplementation->GetWidth();
	}

	int PiguSprite::GetHeight() const
	{
		return mImplementation->GetHeight();
	}

	void PiguSprite::Bind()
	{
		mImplementation->Bind();
	}
}
