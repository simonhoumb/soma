#pragma once

#ifdef SOMA_PLATFORM_WINDOWS
	#ifdef SOMA_BUILD_DLL
		#define SOMA_API __declspec(dllexport)
	#else
		#define SOMA_API __declspec(dllimport)
	#endif	
#else 
	#error Soma only supports Windows
#endif

#define BIT(x) (1 << x)