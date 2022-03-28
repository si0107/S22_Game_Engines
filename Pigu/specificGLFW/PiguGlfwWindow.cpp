#include "pchPigu.h"

#include "PiguGlfwWindow.h"
#include "PiguUtil.h"


namespace Pigu
{
	PiguGlfwWindow::PiguGlfwWindow()
	{
		if(!glfwInit())
			PIGU_LOG("ERROR: GLFW failed to initialize!")
	}

	bool PiguGlfwWindow::CreateWindow(int width, int height, const std::string& windowName)
	{
		mGlfwWindow = glfwCreateWindow(width, height, windowName.c_str(), NULL, NULL);

		if (mGlfwWindow == nullptr)
		{
			PIGU_LOG("ERROR: window creation failed!");
			return false;
		}

		glfwMakeContextCurrent(mGlfwWindow);
		
		return true;
	}


	void PiguGlfwWindow::SwapBuffers()
	{
		glfwSwapBuffers(mGlfwWindow);
	}

	void PiguGlfwWindow::CollectEvents()
	{
		glfwPollEvents();
	}

	int PiguGlfwWindow::GetWidth() const
	{
		int width, height;
		glfwGetWindowSize(mGlfwWindow, &width, &height);

		return width;
	}

	int PiguGlfwWindow::GetHeight() const
	{
		int width, height;
		glfwGetWindowSize(mGlfwWindow, &width, &height);

		return height;
	}

	PiguGlfwWindow::~PiguGlfwWindow()
	{
		if (mGlfwWindow != nullptr)
			glfwDestroyWindow(mGlfwWindow);
	}

}