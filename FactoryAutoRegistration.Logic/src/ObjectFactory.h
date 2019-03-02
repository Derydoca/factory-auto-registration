#pragma once
#include <string>

#if defined DLL_EXPORT
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

class DLLEXPORT ObjectFactory
{
public:
	std::string getSomeString();
};
