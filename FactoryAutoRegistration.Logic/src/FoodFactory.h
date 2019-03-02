#pragma once
#include "pch.h"
#include <string>
#include "FoodObject.h"

class DLLEXPORT FoodFactory
{
public:
	std::string getFactoryStatus();

	std::shared_ptr<FoodObject> orderFood(std::string foodType);
};
