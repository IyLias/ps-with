#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <cstring>
#include <set>

#define MAXNUM  1001

using namespace std;

int U[MAXNUM];
vector<int> summ;

int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &U[i]);
	}

	sort(U, U + N);

	for (int i = 0; i < N; i++)
		for (int j = i; j < N; j++)
			summ.push_back(U[i] + U[j]);
	sort(summ.begin(), summ.end());

	for (int j = N-1; j >= 0; j--)
		for (int k = j; k >= 0; k--)
		{
			int num = U[j] - U[k];
			if (binary_search(summ.begin(), summ.end(), num)) {
				printf("%d\n", U[j]);
				return 0;
			}

		}


	return 0;
}
