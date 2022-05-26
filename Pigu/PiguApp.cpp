#include "pchPigu.h"

#include "PiguApp.h"
#include "GWindow.h"

#include "PiguSprite.h"
#include "PiguShader.h"
#include "PiguRenderer.h"
#include "PiguEvents.h"
#include "PiguKeyCodes.h"

//Implement Run method

namespace Pigu
{
	PiguApp::PiguApp()
	{
		PIGU_LOG("Pigu running...\n");

		Pigu::GWindow::Init();

		Pigu::GWindow::GetWindow()->CreateWindow(1000, 800, "game window");

		PiguRenderer::Init();
	}


	void PiguApp::Run()
	{

		//Pigu::PiguSprite Pigustar{"../Pigu/Assets/Images/Star1.png"};

		//int xPos{ -Pigustar.GetWidth() };
		
		//mframeDuration = 1 frame time
		mNextFrameTime = std::chrono::steady_clock::now() + mframeDuration;
		
		//int x{ 50 }, y{ 50 };
		/*
		auto keyCall = [&x](const KeyPressedPiguEvent& event) 
		{
			//PIGU_LOG(event.GetKeyCode());
			if (event.GetKeyCode() == PIGU_KEY_LEFT) x -= 5;
			else if (event.GetKeyCode() == PIGU_KEY_RIGHT) x += 5;
		};
		auto keyRel = [](const KeyReleasedPiguEvent& event) {PIGU_LOG(event.GetKeyCode()); };
		SetKeyPressedCallBack(keyCall);
		*/
		//SetKeyReleasedCallBack(keyRel);

		//Almost infinite loop to make sure game is rendering 
		while (true) 
		{
			PiguRenderer::ClearScreen();
			OnUpdate();

			//PiguRenderer::Draw(Pigustar, x, y, 1);
			
			//xPos = (xPos + 5) % (Pigu::GWindow::GetWindow()->GetWidth() + Pigustar.GetWidth()) - Pigustar.GetWidth();
			//xPos = (xPos + 5);

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

	void PiguApp::SetKeyPressedCallBack(std::function<void(const KeyPressedPiguEvent&)> keyPressedCallback)
	{
		GWindow::GetWindow()->SetKeyPressedCallback(keyPressedCallback);
	}

	void PiguApp::SetKeyReleasedCallBack(std::function<void(const KeyReleasedPiguEvent&)> keyReleasedCallback)
	{
		GWindow::GetWindow()->SetKeyReleasedCallback(keyReleasedCallback);
	}

}