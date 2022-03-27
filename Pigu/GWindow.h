#pragma once

#include "WindowImplement.h"

namespace Pigu
{
	class GWindow
	{
	public:
		//static objects make it not attached to any instance of this class
		static void Init();
		static GWindow* GetWindow();

		bool CreateWindow(int width, int height, const std::string& windowName);
		void SwapBuffers();
		void CollectEvents();
		int GetWidth() const;
		int GetHeight() const;

	private:
		inline static GWindow* mInstance{ nullptr };
		
		GWindow();

		WindowImplement* mWindow{ nullptr };
	};

}

//		GameWindow::GetWindow()->GetWidth();

