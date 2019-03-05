#pragma once
#include "FoodObject.h"

class Hamburger : public FoodObject, AutoRegister<Hamburger>
{
	AUTOREGISTER(Hamburger);
public:
	virtual int getCalories() const override { return 350; }
	virtual bool isCommonlyOrdered() const override { return false; }
};