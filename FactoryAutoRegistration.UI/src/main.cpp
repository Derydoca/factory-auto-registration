#include <iostream>
#include <string>
#include "../../FactoryAutoRegistration.Logic/src/FoodFactory.h"

int main()
{
	std::cout << "This is an example of the factory pattern with auto registering types.\n";
	std::cout << "Options:\n";
	std::cout << "    Enter \"?\" to see the menu.\n";
	std::cout << "    Type the name of the type of food to make.\n";
	std::cout << "    Type \"exit\" to leave.\n";
	std::cout << "\n";

	std::cout << "* FoodFactory is now open, however, it looks extremely empty inside with the exception of one young employee behind the counter with a nametag that reads \"Dan\". *\n" << std::endl;

	std::cout << "Dan: Welcome to FoodFactory. What would you like to order?\n";

	std::string inputCommand;
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
			break;
		}
		else if(inputCommand == "?")
		{
			std::cout << "Dan: Sorry, but we are still working on putting together the menu. Is there anything else I can help you with?\n";
		}
		else
		{
			auto food = FoodFactory::get().orderFood(inputCommand);
			if (food)
			{
				std::cout << "Dan: Order up! Here is your \"" << food->getTypeName() << "\"!\n";
				std::cout << "* You ate it and now have " << food->getCalories() << " more calories of energy. Good for you! *";
			}
			else
			{
				std::cout << "Dan: I checked in with the kitchen, and it looks like we don't have the ingredients to make \"" << inputCommand << "\". Do you want to order something else?\n";
			}
		}
	}

	return 0;
}
