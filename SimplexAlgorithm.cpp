#include <iostream>
#include <limits>
#include <vector>

/*
* Equation for testing:
* 8x + 12y = z
* 10x + 20y <= 140
* 6x + 8y <= 72
* x, y >= 0
*/

namespace Tableau
{
	std::vector<std::vector<int>> tableau{
		{  10, 20, 1, 0, 140 },
		{  6,  8,  0, 1, 72  },
		{ -8, -12, 0, 0, 0   }
	};
}

constexpr int findPivotColumn(const std::vector<std::vector<int>>& tableau)
{
	int col{ -1 };
	int minValue{ 0 };

	for (std::size_t c{ 0 }; c < 5; ++c)
	{
		if (minValue > tableau[2][c])
		{
			minValue = tableau[2][c];
			col = c;
		}
	}
	return col;
}

constexpr int findPivotRow(const std::vector<std::vector<int>>& tableau, const int pivotCol)
{
	int row{ -1 };
	int minRatio{ std::numeric_limits<int>::max() };

	for (std::size_t r{ 0 }; r < tableau.size() - 1; ++r)
	{
		int element = tableau[r][pivotCol];

		if (element > 0)
		{
			int ratio{ tableau[r].back() / element };
			if (ratio < minRatio)
			{
				minRatio = ratio;
				row = r;
			}
		}
	}

	return row;
}

int main()
{
	int col{ findPivotColumn(Tableau::tableau) };
	int row{ findPivotRow(Tableau::tableau, col) };

	std::cout << col + 1 << '\n';
	std::cout << row + 1 << '\n';

	return 0;
}
