#pragma once
#include "pchPigu.h"

namespace Pigu
{

	class WindowImplement 
	{
	public:
		virtual bool CreateWindow(int width, int height, const std::string& windowName) = 0;
		virtual void SwapBuffers() = 0;
		virtual void CollectEvents() = 0;
		virtual int GetWidth() const = 0;
		virtual int GetHeight() const = 0;
	};

}
