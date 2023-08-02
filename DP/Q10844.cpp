#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <string>

using namespace std;

int dp[101][10];

int main()
{
	int N;
	scanf("%d", &N);

	dp[1][0] = 0;
	for (int i = 1; i < 10; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= N; i++) {

		for (int j = 0; j < 10; j++) {

			if (j == 0) dp[i][j] = dp[i - 1][j + 1];
			else if (j == 9) dp[i][j] = dp[i - 1][j - 1];
			else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1])%1000000000;
		}

	}

	int result = 0;
	for (int i = 0; i < 10; i++)
		result = (result + dp[N][i]) % 1000000000;

	printf("%d\n", result);

	return 0;
}

