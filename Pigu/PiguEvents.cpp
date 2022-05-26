#include "pchPigu.h"
#include "PiguEvents.h"


namespace Pigu 
{
	KeyPressedPiguEvent::KeyPressedPiguEvent(int codeOfKey) : mKeyCode(codeOfKey)
	{
	}

	int KeyPressedPiguEvent::GetKeyCode() const
	{
		return mKeyCode;
	}

	KeyReleasedPiguEvent::KeyReleasedPiguEvent(int codeOfKey): mKeyCode(codeOfKey)
	{
	}

	int KeyReleasedPiguEvent::GetKeyCode() const
	{
		return mKeyCode;
	}


}