#pragma once
#include "FoodObject.h"

class Burrito : public FoodObject
{
public:
	virtual int getCalories() const override { return 800; }
	virtual bool isCommonlyOrdered() const override { return true; }
};

namespace FoodFactoryRegistrations {
	FoodFactoryRegistration<Burrito> _Burrito("Burrito");
}
