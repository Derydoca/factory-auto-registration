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
bool SelfRegister<T>::s_isRegistered = FoodFactory::get().registerGenerator(T::getStaticTypeName(), T::generateInstance);

#define GENINSTANCE(TYPE) \
	static std::shared_ptr<FoodObject> generateInstance() { return std::static_pointer_cast<FoodObject>(std::make_shared<TYPE>()); }\
	static std::string getStaticTypeName() { return #TYPE; }\
	virtual std::string getTypeName() override { return #TYPE; }\
	void __forceRegistration() { s_isRegistered; } // Forces the compiler to run the static initializer even if the boolean is not used anywhere else in the code

class FoodObject
{
public:
	virtual int getCalories() const = 0;
	virtual std::string getTypeName() = 0;
	virtual bool isCommonlyOrdered() const = 0;
};
