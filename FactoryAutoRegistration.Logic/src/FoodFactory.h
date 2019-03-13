#pragma once
#include <string>
#include <unordered_map>

#ifdef BUILD_DLL
#define DLL_INTERFACE __declspec(dllexport)
#else
#define DLL_INTERFACE __declspec(dllimport)
#endif

class FoodObject;

typedef FoodObject*(*foodInstanceGenerator)();

class FoodFactory
{
public:
	DLL_INTERFACE static FoodFactory& get();

	DLL_INTERFACE const char * * getMenu(int & count);
	DLL_INTERFACE FoodObject* orderFood(const char * typeName);
	DLL_INTERFACE bool registerGenerator(const char * typeName, const foodInstanceGenerator& funcCreate);

private:
	FoodFactory();
	FoodFactory(const FoodFactory&);
	~FoodFactory();

	std::unordered_map<std::string, foodInstanceGenerator> m_generators;
};