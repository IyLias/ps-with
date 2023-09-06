#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <cstring>
#include <set>

#define MAXNUM	1001

using namespace std;

int A[MAXNUM];
int B[MAXNUM];

vector<int> partA;
vector<int> partB;

int main()
{
	int T;
	scanf("%d", &T);

	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);

	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = i; j >= 0; j--)
		{
			sum += A[j];
			partA.push_back(sum);
		}
	}

	sort(partA.begin(), partA.end());

	scanf("%d", &m);
	for (int i = 0; i < m; i++)
		scanf("%d", &B[i]);

	for (int i = 0; i < m; i++) {
		int sum = 0;
		for (int j = i; j >= 0; j--)
		{
			sum += B[j];
			partB.push_back(sum);
		}
	}

	long long ans = 0;
	int size = partB.size();
	for (int i = 0; i < size; i++) {

		int target = T - partB[i];
		auto maxIdx = upper_bound(partA.begin(), partA.end(), target) - partA.begin();
		auto minIdx = lower_bound(partA.begin(), partA.end(), target) - partA.begin();
		ans += (maxIdx - minIdx);
	}

	printf("%lld\n", ans);

	return 0;
}
