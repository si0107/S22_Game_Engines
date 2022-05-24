#pragma once

#include "PiguUtil.h"
#include "pchPigu.h"

#define PIGU_FRAMERATE 60

//Namespaces: we can take names and group them together
//We want to avoid name conflicts/collisions
namespace Pigu
{

	class PIGU_API PiguApp
	{
	public:
		void Run();
		virtual void OnUpdate();

	private:
		std::chrono::milliseconds mframeDuration{ 1000 / PIGU_FRAMERATE };
		std::chrono::steady_clock::time_point mNextFrameTime; //Initialized in Air App
	};

}