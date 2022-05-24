#include "pchPigu.h"
#include "PiguOpenGLRenderer.h"
#include "GWindow.h"
#include "glad/glad.h"

namespace Pigu 
{
	void PiguOpenGLRenderer::Draw(Pigu::PiguSprite& picture, int xPos, int yPos, int zPos, Pigu::PiguShader shader)
	{
		int winWidth{ GWindow::GetWindow()->GetWidth() };
		int winHeight{ GWindow::GetWindow()->GetHeight() };

		shader.Bind();
		picture.Bind();

		shader.SetUniform2Ints("windowSize", winWidth, winHeight);
		shader.SetUniform3Ints("spriteCoord", xPos, yPos, zPos); //bottom left corner

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0); //glad draw function
	}

	void PiguOpenGLRenderer::ClearScreen()
	{
		//glClearColor(0.2f, 0.3f, 0.3f, 1.0f); green
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f); //black
		glClear(GL_COLOR_BUFFER_BIT);
	}

}