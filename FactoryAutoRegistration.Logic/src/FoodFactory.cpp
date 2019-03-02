#include "pch.h"
#include "FoodFactory.h"

FoodFactory::FoodFactory()
{
}

FoodFactory::~FoodFactory()
{
}

std::shared_ptr<FoodObject> FoodFactory::orderFood(std::string typeName)
{
	auto it = s_generators.find(typeName);
	if (it != s_generators.end())
	{
		return it->second();
	}

	return nullptr;
}

bool FoodFactory::registerGenerator(const std::string & typeName, const foodInstanceGenerator & funcCreate)
{
	auto it = s_generators.find(typeName);
	if (it == s_generators.end())
	{
		s_generators[typeName] = funcCreate;
	}
	return false;
}

FoodFactory & FoodFactory::get()
{
	static FoodFactory instance;
	return instance;
}
