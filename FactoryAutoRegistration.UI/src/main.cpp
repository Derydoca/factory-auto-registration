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

	auto factory = FoodFactory();
	std::cout << factory.getSomeString() << std::endl;

	std::string inputCommand;
	while (42)
	{
		std::cout << "\nEnter a command: ";
		std::getline(std::cin, inputCommand);

		if (inputCommand == "")
		{
			std::cout << "You're the strong but silent type? I can respect that.\n";
		}
		else if (inputCommand == "exit")
		{
			std::cout << "It's been real.\n";
			break;
		}
		else if(inputCommand == "?")
		{
			std::cout << "I don't know how to do that yet. My bad.\n";
		}
		else
		{
			std::cout << "You want to create one \"" << inputCommand << "\"? I'll see about that later when the kitchen is open.\n";
		}
	}

	return 0;
}
