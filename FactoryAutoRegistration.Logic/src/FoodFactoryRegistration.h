#pragma once
#include "FoodFactory.h"

namespace FoodFactoryRegistrations {

	template <typename T>
	class FoodFactoryRegistration
	{
	public:
		FoodFactoryRegistration(const char* id)
		{
			FoodFactory::get().registerGenerator(
				id,
				[]() { return static_cast<FoodObject*>(new T()); }
			);
		}
	};

}
