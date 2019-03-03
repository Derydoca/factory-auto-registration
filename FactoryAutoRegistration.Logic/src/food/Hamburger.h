#pragma once
#include "FoodObject.h"

class Hamburger : public FoodObject, SelfRegister<Hamburger>
{
public:
	GENINSTANCE(Hamburger);

	Hamburger();

	virtual int getCalories() const override { return 350; }
	virtual bool isCommonlyOrdered() const override { return false; }
};