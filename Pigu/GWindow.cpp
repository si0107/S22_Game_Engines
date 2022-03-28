#include "pchPigu.h"
#include "GWindow.h"
#include "specificGLFW/PiguGlfwWindow.h"

namespace Pigu
{
	void GWindow::Init()
	{
		if(mInstance == nullptr)
			mInstance = new GWindow;
	}

	GWindow* GWindow::GetWindow()
	{
		assert(mInstance);
		return mInstance;
	}

	bool GWindow::CreateWindow(int width, int height, const std::string& windowName)
	{
		return mWindow->CreateWindow(800, 600, "Game Project 22");
	}

	void GWindow::SwapBuffers()
	{
		mWindow->SwapBuffers();
	}

	void GWindow::CollectEvents()
	{
		mWindow->CollectEvents();
	}

	int GWindow::GetWidth() const
	{
		return mWindow->GetWidth();
	}

	int GWindow::GetHeight() const
	{
		return mWindow->GetHeight();
	}

	GWindow::GWindow()
	{
#ifdef PIGU_WINDOWS
	mWindow = new PiguGlfwWindow;
#elif defined PIGU_MACOS
	mWindow = new PiguGlfwWindow;
#elif defined PIGU_LINUX
	mWindow = new PiguGlfwWindow;
#else
	#Unsupported_platform
#endif
	}

}