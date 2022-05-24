#include "pchPigu.h"
#include "PiguShader.h"
#include "piguOpenGL/PiguOpenGLShader.h"

namespace Pigu
{
	PiguShader::PiguShader(const std::string& vertexFile, const std::string& fragmentFile)
	{

#ifdef PIGU_OPENGL
		mImplementation = new PiguOpenGLShader{ vertexFile, fragmentFile };
#else
		#Only_OpenGL_is_supported_for_now
#endif

	}

	void PiguShader::SetUniform3Ints(const std::string& uniformName, int val1, int val2, int val3)
	{
		mImplementation->SetUniform3Ints(uniformName, val1, val2, val3);
	}

	void PiguShader::SetUniform2Ints(const std::string& uniformName, int val1, int val2)
	{
		mImplementation->SetUniform2Ints(uniformName, val1, val2);
	}

	void PiguShader::Bind()
	{
		mImplementation->Bind();
	}
}