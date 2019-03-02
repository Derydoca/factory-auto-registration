#pragma once
#include "pch.h"
#include <string>
#include "FoodObject.h"

typedef std::shared_ptr<FoodObject>(*foodInstanceGenerator)();

class DLLEXPORT FoodFactory
{
public:
	static FoodFactory& get();

	std::string getFactoryStatus();
	std::shared_ptr<FoodObject> orderFood(std::string foodType);

private:
	FoodFactory();
	FoodFactory(const FoodFactory&);

};