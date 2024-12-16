#pragma once

#ifdef SM_PLATFORM_WINDOWS
	#ifdef SM_BUILD_DLL
		#define SOMA_API __declspec(dllexport)
	#else
		#define SOMA_API __declspec(dllimport)
	#endif	
#else 
	#error Soma only supports Windows
#endif