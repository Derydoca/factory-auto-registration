#pragma once
#include <string>
#include <unordered_map>

class FoodObject;

typedef std::shared_ptr<FoodObject>(*foodInstanceGenerator)();

class FoodFactory
{
public:
	__declspec(dllexport) static FoodFactory& get();

	__declspec(dllexport) std::vector<std::string> getMenu();
	__declspec(dllexport) std::shared_ptr<FoodObject> orderFood(std::string typeName);
	__declspec(dllexport) bool registerGenerator(const std::string& typeName, const foodInstanceGenerator& funcCreate);

private:
	FoodFactory();
	FoodFactory(const FoodFactory&);
	~FoodFactory();

	std::unordered_map<std::string, foodInstanceGenerator> m_generators;
};