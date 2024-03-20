#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <cstring>
#include <set>


using namespace std;

int primes[10001];


void sieve() {

	for (int i = 1; i <= 10000; i++)
		primes[i] = 1;

	for (int i = 2; i < 100; i++) {

		if (primes[i] == 1)
			for (int j = 2*i; j <= 10000; j += i)
				primes[j] = 0;

	}

}

int solve(int p1, int p2) {

	bool visited[10000];
	for (int i = 1000; i < 10000; i++)
		visited[i] = false;

	queue<pair<int,int>> que;
	que.push({ p1,0 });


	while (!que.empty()) {

		int p = que.front().first;
		int times = que.front().second;
		que.pop();

		// if reached to the end
		if (p == p2)
			return times;

		int a1 = p / 1000;
		int a2 = (p - 1000 * a1) / 100;
		int a3 = (p - 1000 * a1 - 100 * a2) / 10;
		int a4 = p % 10;

		for (int i = 1; i < 10; i++) {
			if (i == a1) continue;
			if (primes[1000 * i + 100 * a2 + 10 * a3 + a4] && !visited[1000 * i + 100 * a2 + 10 * a3 + a4]) {
				visited[1000 * i + 100 * a2 + 10 * a3 + a4] = true;
				que.push({ 1000 * i + 100 * a2 + 10 * a3 + a4 , times + 1 });

			}
		}

		for (int i = 0; i < 10; i++) {
			if (i == a2) continue;
			if (primes[1000 * a1 + 100 * i + 10 * a3 + a4] && !visited[1000 * a1 + 100 * i + 10 * a3 + a4]) {
				visited[1000 * a1 + 100 * i + 10 * a3 + a4] = true;
				que.push({ 1000 * a1 + 100 * i + 10 * a3 + a4 , times + 1 });
		
			}
		}

		for (int i = 0; i < 10; i++) {
			if (i == a3) continue;
			if (primes[1000 * a1 + 100 * a2 + 10 * i + a4] && !visited[1000 * a1 + 100 * a2 + 10 * i + a4]) {
				visited[1000 * a1 + 100 * a2 + 10 * i + a4] = true;
				que.push({ 1000 * a1 + 100 * a2 + 10 * i + a4 , times + 1 });
			}
		}

		for (int i = 0; i < 10; i++) {
			if (i == a4) continue;
			if (primes[1000 * a1 + 100 * a2 + 10 * a3 + i] && !visited[1000 * a1 + 100 * a2 + 10 * a3 + i]) {
				visited[1000 * a1 + 100 * a2 + 10 * a3 + i] = true;
				que.push({ 1000 * a1 + 100 * a2 + 10 * a3 + i , times + 1 });
			}
		}

	}

	return -1;
}


int main()
{
	int T;
	scanf("%d", &T);

	sieve();

	for (int i = 0; i < T; i++) {

		int p1, p2;
		scanf("%d %d", &p1, &p2);

		int ans = solve(p1, p2);
		if (ans == -1)
			printf("Impossible\n");
		else
			printf("%d\n", ans);
	}

	return 0;
}


