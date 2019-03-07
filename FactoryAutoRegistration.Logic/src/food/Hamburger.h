#pragma once
#include "FoodObject.h"

class Hamburger : public FoodObject
{
public:
	virtual std::string getTypeName() override { return std::string("Hamburger"); };
	virtual int getCalories() const override { return 350; }
	virtual bool isCommonlyOrdered() const override { return false; }
};

namespace FoodFactoryRegistrations {
	FoodFactoryRegistration<Hamburger> _Hamburger("Hamburger");
}
