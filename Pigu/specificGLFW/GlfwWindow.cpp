#include "pch.h"

#include "GlfwWindow.h"
#include "PiguUtil.h"


namespace Pigu
{
	GlfwWindow::GlfwWindow()
	{
		if(!glfwInit())
			PIGU_LOG("ERROR: GLFW failed to initialize!")
	}

	bool GlfwWindow::CreateWindow(int width, int height, const std::string& windowName)
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


	void GlfwWindow::SwapBuffers()
	{
		glfwSwapBuffers(mGlfwWindow);
	}

	void GlfwWindow::CollectEvents()
	{
		glfwPollEvents();
	}

	int GlfwWindow::GetWidth() const
	{
		int width, height;
		glfwGetWindowSize(mGlfwWindow, &width, &height);

		return width;
	}

	int GlfwWindow::GetHeight() const
	{
		int width, height;
		glfwGetWindowSize(mGlfwWindow, &width, &height);

		return height;
	}

	GlfwWindow::~GlfwWindow()
	{
		if (mGlfwWindow != nullptr)
			glfwDestroyWindow(mGlfwWindow);
	}

}