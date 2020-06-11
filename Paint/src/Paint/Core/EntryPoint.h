#pragma once

#ifdef HZ_PLATFORM_WINDOWS
	#ifdef HZ_BUILD_DLL
		#define PAINT_API __declspec(dllexport)
	#else
		#define PAINT_API __declspec(dllimport)
	#endif // HZ_BUILD_DLL
#else
	#error Paint2D only supports windows.
#endif
