#include "pch.h"
#include "FoodFactory.h"

std::string FoodFactory::getFactoryStatus()
{
	return "* FoodFactory is now open, however, it looks extremely empty inside with the exception of one young employee behind the counter with a nametag that reads \"Dan\". *\n";
}

std::shared_ptr<FoodObject> FoodFactory::orderFood(std::string foodType)
{
	return nullptr;
}