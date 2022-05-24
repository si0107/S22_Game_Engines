#pragma once

#include "PiguUtil.h"
#include "PiguShaderImplementation.h"

namespace Pigu {
	
	class PIGU_API PiguShader
	{
	public:
		PiguShader(const std::string& vertexFile, const std::string& fragmentFile);
		void SetUniform3Ints(const std::string& uniformName, int val1, int val2, int val3);
		void SetUniform2Ints(const std::string& uniformName, int val1, int val2);
		void Bind();

	private:
		PiguShaderImplementation* mImplementation;
	};
}

