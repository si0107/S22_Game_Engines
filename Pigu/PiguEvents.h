#pragma once

#include "PiguUtil.h"

namespace Pigu {
	
	//Press key
	class PIGU_API KeyPressedPiguEvent
	{
	public:
		KeyPressedPiguEvent(int codeOfKey);
		KeyPressedPiguEvent() = delete; //disable no paramter constructor

		int GetKeyCode() const;
	private:
		int mKeyCode;
	};

	//Release Key
	class PIGU_API KeyReleasedPiguEvent
	{
	public:
		KeyReleasedPiguEvent(int codeOfKey);
		KeyReleasedPiguEvent() = delete; //disable no paramter constructor

		int GetKeyCode() const;
	private:
		int mKeyCode;
	};
}
