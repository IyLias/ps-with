#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <string>

using namespace std;

#define MAXNUM	1000000

int times[MAXNUM+1];

int main()
{
	int N;
	scanf("%d", &N);

	times[1] = 0, times[2] = 1, times[3] = 1;

	for (int i = 4; i <= N; i++)
	{
		times[i] = times[i - 1];
		if (i % 2 == 0)
			times[i] = min(times[i], times[i / 2]);
		if(i % 3 == 0)
			times[i] = min(times[i], times[i / 3]);

		times[i] += 1;
	}

	printf("%d\n", times[N]);

	return 0;
}

