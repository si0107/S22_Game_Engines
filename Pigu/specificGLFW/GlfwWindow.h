#pragma once

#include "../WindowImplement.h"
#include "GLFW/glfw3.h"

namespace Pigu
{
	class GlfwWindow : public WindowImplement 
	{
	public:
		GlfwWindow();
		virtual bool CreateWindow(int width, int height, const std::string& windowName) override;
		virtual void SwapBuffers() override;
		virtual void CollectEvents() override;
		virtual int GetWidth() const override;
		virtual int GetHeight() const override;
		~GlfwWindow();

	private:
		GLFWwindow* mGlfwWindow{ nullptr };
	};
}