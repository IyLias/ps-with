#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <string>

using namespace std; 

int dp[1001][10];


int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;


	for (int i = 2; i <= N; i++) {

		dp[i][0] = 1;
		for (int j = 1; j < 10; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 10007;
		}

	}


	int result = 0;
	for (int i = 0; i < 10; i++)
		result += dp[N][i];
	printf("%d\n", result);

	return 0;
}

