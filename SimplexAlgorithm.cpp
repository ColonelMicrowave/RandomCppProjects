#include <iostream>
#include <limits>
#include <vector>

/*
* Equation for testing:
* 8x + 12y = z
* 10x + 20y <= 140
* 6x + 8y <= 72
* x, y >= 0
* 
* Answer should be y = 3, x = 8, z = 100
*/

namespace Tableau
{
	std::vector<std::vector<double>> tableau{
		{  6, 8, 1, 0, 72 },
		{  10, 20, 0, 1, 140 },
		{ -8, -12, 0, 0, 0 }
	};
}

int findPivotColumn(const std::vector<std::vector<double>>& tableau)
{
	int col{ -1 };
	double minValue{ 0 };

	for (std::size_t c{ 0 }; c < tableau[0].size(); ++c)
	{
		if (minValue > tableau[2][c])
		{
			minValue = tableau[2][c];
			col = static_cast<int>(c);
		}
	}
	return col;
}

int findPivotRow(const std::vector<std::vector<double>>& tableau, const int pivotCol)
{
	int row{ -1 };
	double minRatio{ std::numeric_limits<double>::infinity() };

	for (std::size_t r{ 0 }; r < tableau.size() - 1; ++r)
	{
		double element = tableau[r][pivotCol];

		if (element > 0)
		{
			double rhs{ tableau[r].back() };
			double ratio{ rhs / element };
			if (ratio < minRatio)
			{
				minRatio = ratio;
				row = static_cast<int>(r);
			}
		}
	}

	return row;
}

void rowCalculations(std::vector<std::vector<double>>& tableau, const int pivotCol, const int pivotRow)
{
	double pivotValue{ tableau[pivotRow][pivotCol] };

	for (std::size_t c{ 0 }; c < tableau[0].size(); ++c)
	{
		tableau[pivotRow][c] = tableau[pivotRow][c] / pivotValue;
	}

	for (std::size_t r{ 0 }; r < tableau.size(); ++r)
	{
		if (static_cast<int>(r) != pivotRow)
		{
			double rowFactor{ tableau[r][pivotCol] };

			for (std::size_t c{ 0 }; c < tableau[0].size(); ++c)
			{
				tableau[r][c] -= rowFactor * tableau[pivotRow][c];
			}
		}
	}
}

int main()
{
	while (true)
	{
		int col{ findPivotColumn(Tableau::tableau) };

		if (col == -1)
		{
			break;
		}

		int row{ findPivotRow(Tableau::tableau, col) };

		rowCalculations(Tableau::tableau, col, row);
	}

	for (const auto& r : Tableau::tableau)
	{
		for (const auto& c : r)
		{
			std::cout << c << "\t\t";
		}
		std::cout << '\n';
	}

	return 0;
}
