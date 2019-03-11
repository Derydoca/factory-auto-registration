#pragma once
#include "FoodFactory.h"
#include "FoodFactoryRegistration.h"

class FoodObject
{
public:
	virtual int getCalories() const = 0;
	virtual bool isCommonlyOrdered() const = 0;
};
