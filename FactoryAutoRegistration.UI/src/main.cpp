#include <iostream>
#include <string>
#include "FoodFactory.h"
#include "FoodObject.h"

void printPreamble()
{
	std::cout << "This is an example of the factory pattern with auto registering types.\n";
	std::cout << "Options:\n";
	std::cout << "    Enter \"?\" to see the menu.\n";
	std::cout << "    Type the name of the type of food to make.\n";
	std::cout << "    Type \"exit\" to leave.\n";
	std::cout << "\n";

	std::cout << "* FoodFactory is now open! *\n";
	std::cout << "* It smells faintly of mexican cuisine inside. *\n";
	std::cout << "* As you step inside, you notice one young employee behind the counter with a nametag that reads \"Dan\". *\n\n";

	std::cout << "Dan: Welcome to FoodFactory. What would you like to order?\n";
}

void printDialogueNoInput()
{
	std::cout << "Dan: Are you going to order something? There are hungry people in line behind you.\n";
	std::cout << "You: ...\n";
	std::cout << "Dan: What would you like to order?\n";
}

void printDialogueExit(const bool willGetSick)
{
	std::cout << "Dan: Thanks for eating at FoodFactory!\n";
	if (willGetSick)
	{
		std::cout << "* Something you ate didn't sit well in your stomach. Better get to a bathroom fast! *";
	}
}

void printDialogueCannotMake(const std::string & itemThatCannotBeMade)
{
	std::cout << "Dan: I checked in with the kitchen, and it looks like we don't have the ingredients to make \"" << itemThatCannotBeMade << "\". Do you want to order something else?\n";
}

int main()
{
	printPreamble();

	std::string inputCommand;
	bool willGetSick = false;

	// Here is an infinite loop so that we can continuously prompt the user until they exit
	while (42)
	{
		// Prompt the user for a command
		std::cout << "You: ";
		std::getline(std::cin, inputCommand);

		// Handle the case where no command was given
		if (inputCommand == "")
		{
			printDialogueNoInput();
		}
		// Handle the exit command so the user can terminate the infinite loop
		else if (inputCommand == "exit")
		{
			printDialogueExit(willGetSick);
			// This break command will terminate the loop
			break;
		}
		// Handle the request to see the menu
		else if (inputCommand == "?")
		{
			// Call getMenu and store the length of the array and pointer to it in numMenuItems and menuItems respecively
			int numMenuItems = 0;
			const char** menuItems = FoodFactory::get().getMenu(numMenuItems);

			// numMenuItems now stores the count of items that exist in the array
			std::cout << "Dan: We have " << numMenuItems << " things:\n";

			// Iterate through each item in the array and print them out
			for (int i = 0; i < numMenuItems; i++)
			{
				std::cout << "         " << menuItems[i] << '\n';
			}

			// Remember to delete the items in the array and the array itself because it is all allocated on the heap
			for (int i = 0; i < numMenuItems; i++)
			{
				delete[] menuItems[i];
			}
			delete[] menuItems;
		}
		else
		{
			// Attempt to order food with the name that the user entered
			FoodObject* food = FoodFactory::get().orderFood(inputCommand.c_str());

			// If we are given an actual pointer to an instance of a FoodObject
			if (food != nullptr)
			{
				// Print out the command and some information about this instance of FoodObject, notice that the result of
				//  getCalories is different depending on the type of food that was created.
				std::cout << "Dan: Order up! Here is your \"" << inputCommand << "\"!\n";
				std::cout << "* You ate it and now have " << food->getCalories() << " more calories of energy. Good for you! *\n";

				// Here is another example of getting unique information from our constructed instance of FoodObject.
				if (!food->isCommonlyOrdered())
				{
					std::cout << "Dan (under his breath): Nobody ever orders those things here... I hope he doesn't get sick.\n";
					willGetSick = true;
				}

				// Remember to delete the FoodObject since it was allocated on the heap
				delete food;
			}
			else
			{
				printDialogueCannotMake(inputCommand);
			}
		}
	}

	return 0;
}
