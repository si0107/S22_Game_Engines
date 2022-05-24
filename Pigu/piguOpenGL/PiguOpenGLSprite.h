#pragma once

#include "PiguSpriteImplementation.h"

namespace Pigu {
	class PiguOpenGLSprite : public PiguSpriteImplementation
	{
	public:
		PiguOpenGLSprite(const std::string& file);
		virtual int GetWidth() const override;
		virtual int GetHeight() const override;
		virtual void Bind() override;
		virtual bool IsBound() const override;

	private:
		//VBO - vertex buffer object
		//VAO - vertex array object
		//EBO - edges buffer object (indices)
		unsigned int mVBO;
		unsigned int mVAO;
		unsigned int mEBO;
		unsigned int mTex;
		int mWidth{ 0 };
		int mHeight{ 0 };
	};

}
