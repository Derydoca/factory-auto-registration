#pragma once
#include "pch.h"
#include <string>
#include <unordered_map>

class FoodObject;

typedef std::shared_ptr<FoodObject>(*foodInstanceGenerator)();

class DLLEXPORT FoodFactory
{
public:
	static FoodFactory& get();

	std::shared_ptr<FoodObject> orderFood(std::string typeName);
	bool registerGenerator(const std::string& typeName, const foodInstanceGenerator& funcCreate);

private:
	FoodFactory();
	FoodFactory(const FoodFactory&);
	~FoodFactory();

	std::unordered_map<std::string, foodInstanceGenerator> s_generators;
};