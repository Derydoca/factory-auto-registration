#pragma once
#include "FoodObject.h"

class Burrito : public FoodObject, SelfRegister<Burrito>
{
public:
	GENINSTANCE(Burrito);

	Burrito();

	virtual int getCalories() const override { return 800; }
	virtual bool isCommonlyOrdered() const override { return true; }
};