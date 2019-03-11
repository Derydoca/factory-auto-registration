#include "FoodFactory.h"

FoodFactory::FoodFactory()
{
}

FoodFactory::~FoodFactory()
{
}

FoodObject* FoodFactory::orderFood(std::string typeName)
{
	auto it = m_generators.find(typeName);
	if (it != m_generators.end())
	{
		return it->second();
	}

	return nullptr;
}

bool FoodFactory::registerGenerator(const std::string & typeName, const foodInstanceGenerator & funcCreate)
{
	return m_generators.insert(std::make_pair(typeName, funcCreate)).second;
}

void FoodFactory::getMenu(int & count, std::string* & items)
{
	count = m_generators.size();
	items = new std::string[4];

	int i = 0;
	for (auto generator : m_generators)
	{
		items[i++] = generator.first;
	}
}

FoodFactory & FoodFactory::get()
{
	static FoodFactory instance;
	return instance;
}
