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

	DLL_INTERFACE void getMenu(int & count, std::string* & items);
	DLL_INTERFACE FoodObject* orderFood(std::string typeName);
	DLL_INTERFACE bool registerGenerator(const std::string& typeName, const foodInstanceGenerator& funcCreate);

private:
	FoodFactory();
	FoodFactory(const FoodFactory&);
	~FoodFactory();

	std::unordered_map<std::string, foodInstanceGenerator> m_generators;
};