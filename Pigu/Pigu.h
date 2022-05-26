#pragma once

#include "PiguApp.h"
#include "GWindow.h"
#include "PiguSprite.h"
#include "PiguShader.h"
#include "PiguRenderer.h"
#include "PiguKeyCodes.h"
#include "PiguEvents.h"


//MACRO for creating a method to run the gameClass we supply it
#define PIGU_APPLICATION_START(gameclass) \
\
int main()\
{\
	gameclass game;\
	game.Run();\
}
