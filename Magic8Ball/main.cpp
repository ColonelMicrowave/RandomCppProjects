#include <iostream>
#include <limits>
#include <string>
#include "get8BallResponses.h"


bool playAgain()
{
	while (true)
	{
		char playAgain{};
		std::cout << "Would you like to ask another question? (y/n): ";
		std::cin >> playAgain;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else if (playAgain == 'y' || playAgain == 'Y')
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return true;
		}
		else if (playAgain == 'n' || playAgain == 'N')
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return false;
		}
		else
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Please try again.\n";
		}
	}
}

int main()
{
	std::cout << "Welcome to the 8-Ball program!\n";
	
	while (true)
	{
		std::cout << "Ask the 8-ball a question: ";
		std::string question{};
		std::getline(std::cin >> std::ws, question);

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
		{
			get8BallResponse();
			if (!playAgain())
				break;
		}
	}

	std::cout << "Thank you for using the 8-Ball program!\n";
	return 0;
}
