//IN PIGU FOLDER


#include "pchPigu.h"

#include "glad/glad.h"
#include "PiguGlfwWindow.h"
#include "PiguUtil.h"


namespace Pigu
{
	PiguGlfwWindow::PiguGlfwWindow()
	{
		if (!glfwInit())
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
		glfwSwapInterval(1); //enables buffering?

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			PIGU_LOG("ERROR: GLAD failed to initialize!");

		glfwSetWindowUserPointer(mGlfwWindow, &mCallBacks);

		//lambda function [] = implementation of keyCallBack
		glfwSetKeyCallback(mGlfwWindow, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				if (action == GLFW_PRESS) //if (action == GLFW_PRESS || action == GLFW_REPEAT)
				{
					Callbacks* userPointer{ (Callbacks*)glfwGetWindowUserPointer(window) };

					KeyPressedPiguEvent event{ key };
					userPointer->keyPressedCallback(event);
				}
				else if (action == GLFW_RELEASE)
				{
					Callbacks* userPointer{ (Callbacks*)glfwGetWindowUserPointer(window) };

					KeyReleasedPiguEvent event{ key };
					userPointer->keyReleasedCallback(event);
				}
			}
		);

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

	void PiguGlfwWindow::SetKeyPressedCallback(std::function<void(const KeyPressedPiguEvent&)> keyPressedCallback)
	{
		mCallBacks.keyPressedCallback = keyPressedCallback;
	}

	void PiguGlfwWindow::SetKeyReleasedCallback(std::function<void(const KeyReleasedPiguEvent&)> keyReleasedCallback)
	{
		mCallBacks.keyReleasedCallback = keyReleasedCallback;
	}

}