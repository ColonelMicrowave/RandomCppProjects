#include <iostream>

namespace Constants
{
	const double R{ 8.31 };  // Gas constant
}

void calculateAndPrintValue(char solveFor, double volume, double moles, double temperature, double pressure)
{
	switch (solveFor)
	{
	case 'P':
		std::cout << "The pressure of the gas is " << (moles * Constants::R * temperature) / volume << " pascals. \n";
		break;
	case 'V':
		std::cout << "The volume of the gas is " << (moles * Constants::R * temperature) / pressure << " metres cubed. \n";
		break;
	case 'n':
		std::cout << "The number of moles of the gas is " << (pressure * volume) / (Constants::R * temperature) << ". \n";
		break;
	case 'T':
		std::cout << "The temperature of the gas is " << (pressure * volume) / (moles * Constants::R) << " Kelvin. \n";
		break;
	}
}

void getUserValues(char solveFor)
{
	double V{};
	double n{};
	double T{};
	double P{};
	if (solveFor != 'V')
	{
		std::cout << "Enter the volume of the gas in cubic metres: ";
		std::cin >> V;
	}
	if (solveFor != 'n')
	{
		std::cout << "Enter the number of moles of the gas: ";
		std::cin >> n;
	}
	if (solveFor != 'T')
	{
		std::cout << "Enter the temperature of the gas in Kelvin: ";
		std::cin >> T;
	}
	if (solveFor != 'P')
	{
		std::cout << "Enter the pressure of the gas in pascals: ";
		std::cin >> P;
	}

	calculateAndPrintValue(solveFor, V, n, T, P);
}

void rearrangeEquation()
{
	std::cout << "What do you want to solve for? (P, V, n, T) \n";
	char solveFor{};
	std::cin >> solveFor;

	if ((solveFor != 'P') && (solveFor != 'V') && (solveFor != 'n') && (solveFor != 'T'))
	{
		std::cout << "Invalid input. \n";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		rearrangeEquation();
	}
	else
	{
		getUserValues(solveFor);
	}
}

int main()
{
	rearrangeEquation();

	return 0;
}
