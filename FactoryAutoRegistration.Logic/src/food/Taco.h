#pragma once
#include "FoodObject.h"

class Taco : public FoodObject
{
public:
	virtual int getCalories() const override { return 200; }
	virtual bool isCommonlyOrdered() const override { return true; }
};

namespace FoodFactoryRegistrations {
	FoodFactoryRegistration<Taco> _Taco("Taco");
}
