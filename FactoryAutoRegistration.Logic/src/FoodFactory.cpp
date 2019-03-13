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

const char * * FoodFactory::getMenu(int & count)
{
	count = m_generators.size();
	const char * * arrayHead = new const char * [count];

	int i = 0;
	for (auto g : m_generators)
	{
		size_t bufferSize = g.first.length() + 1;
		char * generatorIdBuffer = new char[bufferSize];
		strncpy_s(generatorIdBuffer, bufferSize, g.first.c_str(), g.first.length());
		arrayHead[i++] = generatorIdBuffer;
	}

	return arrayHead;
}

FoodFactory & FoodFactory::get()
{
	static FoodFactory instance;
	return instance;
}
