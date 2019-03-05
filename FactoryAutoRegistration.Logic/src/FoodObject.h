#pragma once
#include <string>
#include "FoodFactory.h"
#include "AutoRegister.h"

class FoodObject
{
public:
	virtual int getCalories() const = 0;
	virtual std::string getTypeName() = 0;
	virtual bool isCommonlyOrdered() const = 0;
};
