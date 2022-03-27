#include "pch.h"

#include "PiguApp.h"

//Implement Run method

namespace Pigu
{
	void PiguApp::Run()
	{
		PIGU_LOG("Pigu running...\n");

		//Almost infinite loop to make sure game is rendering 
		while (true) 
		{
			OnUpdate();
		}
	}

	//Whatever happens on each function of the Run loop, update here
	void PiguApp::OnUpdate()
	{
		//Currently it will do nothing
	}

}