#pragma once

#ifdef GGE_PLATFORM_WINDOWS
	#ifdef GGE_BUILD_DLL
		#define GanjGameEngine_API __declspec(dllexport)
	#else
		#define GanjGameEngine_API __declspec(dllimport)
	#endif // !GGE_BUILD_DLL
#else
	#error GanjGameEngine only supports Windows!

#endif