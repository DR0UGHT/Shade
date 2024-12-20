#pragma once

#ifdef SD_PLATFORM_WINDOWS
	#ifdef SD_BUILD_DLL
		#define SHADE_API __declspec(dllexport)
	#else
		#define SHADE_API __declspec(dllimport)
	#endif
#else
	#error Shade only supports Windows!
#endif

#define BIT(x) (1 << x)