#pragma once

//IN PIGU FOLDER

#include "../WindowImplement.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace Pigu
{
	class PiguGlfwWindow : public WindowImplement
	{
	public:
		PiguGlfwWindow();
		virtual bool CreateWindow(int width, int height, const std::string& windowName) override;
		virtual void SwapBuffers() override;
		virtual void CollectEvents() override;
		virtual int GetWidth() const override;
		virtual int GetHeight() const override;
		~PiguGlfwWindow();

	private:
		GLFWwindow* mGlfwWindow{ nullptr };
	};
}