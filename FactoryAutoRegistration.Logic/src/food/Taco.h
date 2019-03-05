#pragma once
#include "FoodObject.h"

class Taco : public FoodObject, AutoRegister<Taco>
{
	AUTOREGISTER(Taco);
public:
	virtual int getCalories() const override { return 200; }
	virtual bool isCommonlyOrdered() const override { return true; }
};