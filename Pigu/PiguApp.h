#pragma once

#include "PiguUtil.h"

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

	};

}