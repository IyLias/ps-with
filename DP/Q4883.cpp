#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <string>
#include <set>

#define MAXNUM	100000

int tri_graph[MAXNUM][3];

using namespace std;

int main()
{
	int times = 1;
	while (true) {
		int N;
		scanf("%d", &N);

		if (N == 0) break;

		for (int i = 0; i < N; i++)
		{
			scanf("%d %d %d", &tri_graph[i][0], &tri_graph[i][1], &tri_graph[i][2]);
		}

		tri_graph[0][2] += tri_graph[0][1];
		tri_graph[1][0] += tri_graph[0][1];

		tri_graph[1][1] += min(min(tri_graph[0][1],tri_graph[1][0]),tri_graph[0][2]);
		tri_graph[1][2] += min(min(tri_graph[0][1],tri_graph[1][1]),tri_graph[0][2]);

		for (int i = 2; i < N; i++) {

			tri_graph[i][0] += min(tri_graph[i - 1][0], tri_graph[i - 1][1]);
			tri_graph[i][1] += min(min(min(tri_graph[i - 1][0], tri_graph[i - 1][1]),tri_graph[i-1][2]),tri_graph[i][0]);
			tri_graph[i][2] += min(min(tri_graph[i - 1][1], tri_graph[i - 1][2]),tri_graph[i][1]);
		}

		printf("%d. %d\n", times, tri_graph[N-1][1]);
		times++;
	}

	return 0;
}

