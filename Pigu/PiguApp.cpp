#include "pchPigu.h"

#include "PiguApp.h"
#include "GWindow.h"

#include "PiguSprite.h"
#include "PiguShader.h"
#include "PiguRenderer.h"


//Implement Run method

namespace Pigu
{
	void PiguApp::Run()
	{
		PIGU_LOG("Pigu running...\n");

		Pigu::GWindow::Init();
		

		Pigu::GWindow::GetWindow()->CreateWindow(800, 600, "game window");

		PiguRenderer::Init();

		Pigu::PiguSprite Pigustar{"../Pigu/Assets/Images/Star1.png"};

		int xPos{ -Pigustar.GetWidth() };
		
		//mframeDuration = 1 frame time
		mNextFrameTime = std::chrono::steady_clock::now() + mframeDuration;

		//Almost infinite loop to make sure game is rendering 
		while (true) 
		{
			OnUpdate();

			PiguRenderer::ClearScreen();

			PiguRenderer::Draw(Pigustar, xPos, 20, 1);
			
			//xPos = (xPos + 5) % (Pigu::GWindow::GetWindow()->GetWidth() + Pigustar.GetWidth()) - Pigustar.GetWidth();
			xPos = (xPos + 5);

			std::this_thread::sleep_until(mNextFrameTime);

			Pigu::GWindow::GetWindow()->SwapBuffers();
			Pigu::GWindow::GetWindow()->CollectEvents();

			mNextFrameTime += mframeDuration;
		}
	}

	//Whatever happens on each function of the Run loop, update here
	void PiguApp::OnUpdate()
	{
		//Currently it will do nothing
	}

}