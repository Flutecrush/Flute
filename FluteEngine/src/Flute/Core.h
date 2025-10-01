#pragma once

#ifdef FL_PLATFORM_WINDOWS
	#ifdef FL_BUILD_DLL
		#define FLUTE_API __declspec(dllexport)
	#else
		#define FLUTE_API __declspec(dllimport)
	#endif
#else
	#error FluteEngine only supports Windows!
#endif