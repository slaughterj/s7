#include <dlfcn.h>

#if defined(_MSC_VER)
    #define THREAD_LOCAL __declspec(thread)
#else
	#define THREAD_LOCAL _Thread_local
#endif

THREAD_LOCAL static char error_msg[1024];

HMODULE dlopen(const char *lib_name, int load_type)
{
	if(lib_name == NULL)
	{
		return NULL;
	}
	
	return LoadLibraryEx(lib_name, NULL, load_type);
}

FARPROC dlsym(HMODULE lib, const char* func_name)
{
	return GetProcAddress(lib, func_name);
}


char* dlerror()
{
	DWORD dword = GetLastError();
	DWORD fmsg = FormatMessage(FORMAT_MESSAGE_IGNORE_INSERTS | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL, dword, 0, error_msg, sizeof(error_msg), NULL);
		
		if(!fmsg)
		{
			return "Unknown or non system error";
		}
		return error_msg;
}

int dlclose(HMODULE mod)
{
	return FreeLibrary(mod);
}

	