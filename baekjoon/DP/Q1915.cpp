#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <string>

using namespace std;

int mmap[1001][1001];
int dp[1001][1001];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {

		string s;
		cin >> s;

		for (int j = 1; j <= m; j++)
			mmap[i][j] = s[j-1] - '0';
	}

	for(int i=1;i<=n;i++)
		for (int j = 1; j <= m; j++) {

			if (mmap[i][j] == 0)
				dp[i][j] = 0;
			else
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;

		}

	int max_length = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (dp[i][j] > max_length)
				max_length = dp[i][j];

	printf("%d\n", max_length * max_length);
}
