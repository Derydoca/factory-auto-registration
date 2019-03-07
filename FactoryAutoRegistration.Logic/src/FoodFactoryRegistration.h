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
				[]() { return std::static_pointer_cast<FoodObject>(std::make_shared<T>()); });
		}
	};

}
