#pragma once

#include "pch.h"

#ifdef PIGU_LIB
	#define PIGU_API __declspec(dllexport)
#else
	#define PIGU_API __declspec(dllimport)
#endif

#ifdef PIGU_DEBUG
	#define PIGU_LOG(x) std::cout<<x<<std::endl;
#else
	#define PIGU_LOG(x)
#endif
