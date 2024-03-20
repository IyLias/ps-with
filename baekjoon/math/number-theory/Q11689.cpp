#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <string>
#include <set>


using namespace std;

vector<long long> prime_factors;

void factorization(long long n) {
	
	long long number = n;

	for (long long i = 2;i*i<=n; i++)
	{
		if (number % i == 0)
		{
			while(number%i == 0)
				number /= i;
			prime_factors.push_back(i);
		}

	}

	if(number > 1)
		prime_factors.push_back(number);
}

long long phi(long long n) {

	long long result = n;
	for (int i = 0; i < prime_factors.size(); i++) {
		result /= prime_factors[i];
		result *= (prime_factors[i] - 1);
	}

	return result;
}


int main()
{
	long long n;
	scanf("%lld", &n);
	
	if (n >= 2)
		factorization(n);

	printf("%lld\n", phi(n));

}

