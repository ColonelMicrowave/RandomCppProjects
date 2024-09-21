#include <iostream>
#include <limits>

void ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void fibonacci(int terms)
{
	int first{ 0 };
	int second{ 1 };
	int third{ 0 };

	for (int i{ 0 }; i < terms; ++i)
	{
		if (i <= 1)
		{
			std::cout << i << ' ';
		}
		else
		{
			third = first + second;
			std::cout << third << ' ';
			first = second;
			second = third;
		}
	}
}

int main()
{
	while (true)
	{
		std::cout << "Enter the number of terms you want in the Fibonacci sequence: ";
		int terms{ };
		std::cin >> terms;

		if (std::cin.fail())
		{
			std::cin.clear();
			ignoreLine();
			std::cout << "Invalid input. Please enter a positive integer.\n";
		}
		else if (terms <= 0)
		{
			ignoreLine();
			std::cout << "You must enter a positive integer.\n";
		}
		else
		{
			ignoreLine();
			std::cout << "The first " << terms << " terms in the Fibonacci sequence are: ";
			fibonacci(terms);
			std::cout << '\n';
			break;
		}
	}

	return 0;
}
