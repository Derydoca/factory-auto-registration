#include <iostream>
#include <string>
#include "../../FactoryAutoRegistration.Logic/src/FoodFactory.h"
#include "../../FactoryAutoRegistration.Logic/src/FoodObject.h"

int main()
{
	std::cout << "This is an example of the factory pattern with auto registering types.\n";
	std::cout << "Options:\n";
	std::cout << "    Enter \"?\" to see the menu.\n";
	std::cout << "    Type the name of the type of food to make.\n";
	std::cout << "    Type \"exit\" to leave.\n";
	std::cout << "\n";

	std::cout << "* FoodFactory is now open! *\n";
	std::cout << "* It smells faintly of mexican cuisine inside. *\n";
	std::cout << "* As you step inside, you notice one young employee behind the counter with a nametag that reads \"Dan\". *\n" << std::endl;

	std::cout << "Dan: Welcome to FoodFactory. What would you like to order?\n";

	std::string inputCommand;
	bool willGetSick = false;
	while (42)
	{
		std::cout << "You: ";
		std::getline(std::cin, inputCommand);

		if (inputCommand == "")
		{
			std::cout << "Dan: Are you going to order something? There are hungry people in line behind you.\n";
			std::cout << "You: ...\n";
			std::cout << "Dan: What would you like to order?\n";
		}
		else if (inputCommand == "exit")
		{
			std::cout << "Dan: Thanks for eating at FoodFactory!\n";
			if (willGetSick)
			{
				std::cout << "* Something you ate didn't sit well in your stomach. Better get to a bathroom fast! *";
			}
			break;
		}
		else if(inputCommand == "?")
		{
			auto menu = FoodFactory::get().getMenu();
			std::cout << "Dan: We have " << menu.size() << " things on the menu:\n";
			for (auto item : menu)
			{
				std::cout << "         " << item << std::endl;
			}
		}
		else
		{
			auto food = FoodFactory::get().orderFood(inputCommand);
			if (food)
			{
				std::cout << "Dan: Order up! Here is your \"" << food->getTypeName() << "\"!\n";
				std::cout << "* You ate it and now have " << food->getCalories() << " more calories of energy. Good for you! *\n";
				if (!food->isCommonlyOrdered())
				{
					std::cout << "Dan (under his breath): Nobody ever orders those things here... I hope he doesn't get sick.\n";
					willGetSick = true;
				}
			}
			else
			{
				std::cout << "Dan: I checked in with the kitchen, and it looks like we don't have the ingredients to make \"" << inputCommand << "\". Do you want to order something else?\n";
			}
		}
	}

	return 0;
}
