#pragma once
#include "FoodObject.h"

class Burrito : public FoodObject, AutoRegister<Burrito>
{
	AUTOREGISTER(Burrito);
public:
	virtual int getCalories() const override { return 800; }
	virtual bool isCommonlyOrdered() const override { return true; }
};