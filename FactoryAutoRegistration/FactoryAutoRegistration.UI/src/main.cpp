#include "pch.h"
#include <iostream>
#include <string>

int main()
{
	std::cout << "This is an example of the factory pattern with auto registering types.\n";
	std::cout << "Options:\n";
	std::cout << "    Enter \"?\" to see a list of available types.\n";
	std::cout << "    Type \"exit\" to close the application.\n";
	std::cout << "    Type the name of the type you would like to create an instance of.\n";

	std::string inputCommand;
	while (1)
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
			std::cout << "You want to create one \"" << inputCommand << "\" object? I'll see about that later when I am smarter.\n";
		}
	}

	return 0;
}
