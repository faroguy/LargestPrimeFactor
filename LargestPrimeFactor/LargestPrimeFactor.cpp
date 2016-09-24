// LargestPrimeFactor.cpp : Uses CUDA to find the prime factors of a number.
//

#include "stdafx.h"
int64_t findLargestPrimeFactor(int64_t input, int64_t startFactor = 3);
int main(void)
{

	printf("Finding largest prime factor of 600851475143\n");

	int64_t result = findLargestPrimeFactor(600851475143);

	printf("Result is %" PRId64 "\n", result);
	return 0;
}

int64_t findLargestPrimeFactor(int64_t input, int64_t startFactor)
{
	if (input == 0)
	{
		return 0;
	}
	if (input % 2 == 0)
	{
		return input / 2;
	}
	int64_t factor = startFactor;
	for (; factor < input / 3; factor+=2)
	{
		if (input % factor == 0)
		{
			return findLargestPrimeFactor(input / factor, factor + 2);
		}
	}

	return input;
}
