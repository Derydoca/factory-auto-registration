#pragma once

namespace FoodFactoryRegistrations {

	template <typename T>
	class FoodFactoryRegistration
	{
	public:
		FoodFactoryRegistration(const std::string & id)
		{
			FoodFactory::get().registerGenerator(
				id,
				[]() { return static_cast<FoodObject*>(new T()); }
			);
		}
	};

}
