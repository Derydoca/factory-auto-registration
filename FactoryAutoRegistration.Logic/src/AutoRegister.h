#pragma once

template <typename T>
class AutoRegister
{
protected:
	static bool s_isRegistered;
};

template <typename T>
bool AutoRegister<T>::s_isRegistered = FoodFactory::get().registerGenerator(T::getStaticTypeName(), T::generateInstance);

#define AUTOREGISTER(TYPE) \
public:\
	static std::shared_ptr<FoodObject> generateInstance() { return std::static_pointer_cast<FoodObject>(std::make_shared<TYPE>()); }\
	static std::string getStaticTypeName() { return #TYPE; }\
	virtual std::string getTypeName() override { return #TYPE; }\
private:\
	void __forceRegistration() { s_isRegistered; } // Forces the compiler to run the static initializer even if the boolean is not used anywhere else in the code
