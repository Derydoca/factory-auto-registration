#pragma once
#include "FoodObject.h"

class Taco : public FoodObject, SelfRegister<Taco>
{
public:
	GENINSTANCE(Taco);

	Taco();

	virtual int getCalories() const override { return 200; }
};