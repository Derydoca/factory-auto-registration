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
	auto it = m_generators.find(typeName);
	if (it != m_generators.end())
	{
		return it->second();
	}

	return nullptr;
}

bool FoodFactory::registerGenerator(const std::string & typeName, const foodInstanceGenerator & funcCreate)
{
	auto it = m_generators.find(typeName);
	if (it == m_generators.end())
	{
		m_generators[typeName] = funcCreate;
	}
	return false;
}

std::vector<std::string> FoodFactory::getMenu()
{
	auto menuItems = std::vector<std::string>();
	menuItems.reserve(m_generators.size());
	for (auto generator : m_generators)
	{
		menuItems.push_back(generator.first);
	}
	return menuItems;
}

FoodFactory & FoodFactory::get()
{
	static FoodFactory instance;
	return instance;
}
