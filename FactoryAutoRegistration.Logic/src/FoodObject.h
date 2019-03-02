#pragma once
#include <string>
#include "FoodFactory.h"

template <typename T>
class SelfRegister
{
protected:
	static bool s_isRegistered;
};

template <typename T>
bool SelfRegister<T>::s_isRegistered = FoodFactory::get().registerGenerator(T::getTypeName(), T::generateInstance);

#define GENINSTANCE(TYPE) \
	static std::shared_ptr<FoodObject> generateInstance() { return std::static_pointer_cast<FoodObject>(std::make_shared<TYPE>()); }\
	static std::string getTypeName() { return #TYPE; }\
	void __forceRegistration() { s_isRegistered; } // Forces the compiler to run the static initializer even if the boolean is not used anywhere else in the code

class FoodObject
{
public:
	virtual int getCalories() const = 0;
};
