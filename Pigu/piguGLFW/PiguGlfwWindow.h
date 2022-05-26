#pragma once

//IN PIGU FOLDER

#include "../WindowImplement.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "PiguEvents.h"

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

		virtual void SetKeyPressedCallback(std::function<void(const KeyPressedPiguEvent&)> keyPressedCallback) override;
		virtual void SetKeyReleasedCallback(std::function<void(const KeyReleasedPiguEvent&)> keyReleasedCallback) override;

	private:
		//all function methods
		struct Callbacks
		{
			std::function<void(const KeyPressedPiguEvent&)> keyPressedCallback{ [](const KeyPressedPiguEvent&) {} };
			std::function<void(const KeyReleasedPiguEvent&)> keyReleasedCallback{ [](const KeyReleasedPiguEvent&) {} };
		} mCallBacks;
		GLFWwindow* mGlfwWindow{ nullptr };
	};
}