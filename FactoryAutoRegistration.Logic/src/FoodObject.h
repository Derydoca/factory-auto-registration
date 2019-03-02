#pragma once
#include <string>

class FoodObject
{
public:
	virtual int getCalories() const = 0;
	virtual std::string getTypeName() const = 0;
};
