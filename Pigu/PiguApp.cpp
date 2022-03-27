#include "pch.h"

#include "PiguApp.h"
#include "GWindow.h"

//Implement Run method

namespace Pigu
{
	void PiguApp::Run()
	{
		PIGU_LOG("Pigu running...\n");

		Pigu::GWindow::Init();
		

		Pigu::GWindow::GetWindow()->CreateWindow(800, 600, "game window");
		

		//Almost infinite loop to make sure game is rendering 
		while (true) 
		{
			OnUpdate();

			Pigu::GWindow::GetWindow()->SwapBuffers();
			Pigu::GWindow::GetWindow()->CollectEvents();
		}
	}

	//Whatever happens on each function of the Run loop, update here
	void PiguApp::OnUpdate()
	{
		//Currently it will do nothing
	}

}