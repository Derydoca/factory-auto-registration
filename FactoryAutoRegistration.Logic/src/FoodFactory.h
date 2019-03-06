#pragma once
#include <string>
#include <unordered_map>

#ifdef BUILD_DLL
#define DLL_INTERFACE __declspec(dllexport)
#else
#define DLL_INTERFACE __declspec(dllimport)
#endif

class FoodObject;

typedef std::shared_ptr<FoodObject>(*foodInstanceGenerator)();

class FoodFactory
{
public:
	DLL_INTERFACE static FoodFactory& get();

	DLL_INTERFACE std::vector<std::string> getMenu();
	DLL_INTERFACE std::shared_ptr<FoodObject> orderFood(std::string typeName);
	DLL_INTERFACE bool registerGenerator(const std::string& typeName, const foodInstanceGenerator& funcCreate);

private:
	FoodFactory();
	FoodFactory(const FoodFactory&);
	~FoodFactory();

	std::unordered_map<std::string, foodInstanceGenerator> m_generators;
};