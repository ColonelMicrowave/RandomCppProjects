#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "random.h"

unsigned long long stPetersburgParadox()
{
	int tosses{ 1 };

	while (Random::get(0, 1) == 0)
	{
		++tosses;
	}

	return (1ULL << (tosses - 1));
}

int main()
{
	const int simulationsPerBatch{ 100000000 };
	const int numBatches{ 15 };
	double batchAverages[numBatches]{};

	for (int batch{ 0 }; batch < numBatches; ++batch)
	{
		unsigned long long totalPayoff{ 0 };

		for (int i{ 0 }; i < simulationsPerBatch; ++i)
		{
			totalPayoff += stPetersburgParadox();
		}

		batchAverages[batch] = static_cast<double>(totalPayoff / simulationsPerBatch);

		std::cout << std::fixed << std::setprecision(2);
		std::cout << "Batch " << (batch + 1) << " average: " << batchAverages[batch] << '\n';
	}

	double overallAverage{ 0.0 };
	for (int i{ 0 }; i < numBatches; ++i)
	{
		overallAverage += batchAverages[i];
	}
	overallAverage /= numBatches;

	std::cout << "\nAverage payoff after " 
		<< numBatches << " batches: " 
		<< std::fixed << std::setprecision(2) << overallAverage << '\n';

	return 0;
}
