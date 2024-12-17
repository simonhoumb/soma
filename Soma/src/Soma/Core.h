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

#ifdef SOMA_ENABLE_ASSERTS
	#define SOMA_CORE_ASSERT(x, ...) { if(!(x)) { SOMA_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define SOMA_CLIENT_ASSERT(x, ...) { if(!(x)) { SOMA_CLIENT_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define SOMA_CORE_ASSERT(x, ...)
#define SOMA_CLIENT_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#include "smpch.h"
