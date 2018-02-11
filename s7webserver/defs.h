#pragma once

#if defined(_WIN32)
  #if defined(DLL_EXPORT)
    #define EXPORT_LIB __declspec(dllexport)
  #elif defined(DLL_IMPORT)
	#define EXPORT_LIB __declspec(dllimport)
  #else
	  #define EXPORT_LIB
  #endif
#else
  #define EXPORT_LIB
#endif

