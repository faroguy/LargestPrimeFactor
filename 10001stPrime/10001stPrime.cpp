// 100001stPrime.cpp
//

#include "stdafx.h"

int64_t findSpecificPrime(int targetPrime);

int main()
{
	printf("Finding the 10001th prime\n");
	int64_t result = findSpecificPrime(10001);

	printf("Result is %" PRId64 "\n", result);

    return 0;
}

int64_t findSpecificPrime(int targetPrime)
{
	std::vector<int64_t> primeList(targetPrime);
	primeList[0] = 2;
	primeList[1] = 3;
	primeList[2] = 5;
	for (int prime = 6; primeList.back() == 0; prime++)
	{
		bool isPrime = true;
		int divIndex = 0;
		for (; primeList[divIndex] != 0 && isPrime; ++divIndex)
		{
			if (prime % primeList[divIndex] == 0)
			{
				isPrime = false;
			}
		}
		if (isPrime)
		{
			primeList[divIndex] = prime;
		}
	}

	return primeList.back();
}