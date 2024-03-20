#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <string>
#include <set>

using namespace std;

int N, M;
long long max_area = -1;
int area[51][51];


int get_sum(int lx, int ly, int rx, int ry) {

	int sum = 0;
	for (int i = lx; i <= rx; i++)
		for (int j = ly; j <= ry; j++)
			sum += area[i][j];

	return sum;
}


int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		string row;
		cin >> row;
		for (int j = 0; j < M; j++)
			area[i][j] = row[j]-'0';

	}

	
	for(int i=0;i<M-2;i++)
		for (int j = i + 1; j < M - 1; j++)
		{
			long long sum1 = get_sum(0, 0, N - 1, i);
			long long sum2 = get_sum(0, i+1, N - 1,j);
			long long sum3 = get_sum(0, j+1, N - 1, M-1);

			max_area = max(max_area, sum1 * sum2 * sum3);
		}

	for (int i = 0; i < N - 2; i++)
		for (int j = i + 1; j < N - 1; j++)
		{
			long long sum1 = get_sum(0, 0, i, M-1);
			long long sum2 = get_sum(i+1,0,j,M-1);
			long long sum3 = get_sum(j+1, 0, N - 1, M - 1);

			max_area = max(max_area, sum1 * sum2 * sum3);
		}


	for (int i = 0; i < N-1 ; i++)
		for (int j = 0; j < M-1 ; j++)
		{
			long long sum1 = get_sum(0, 0, i, j);
			long long sum2 = get_sum(0, j+1, i, M - 1);
			long long sum3 = get_sum(i + 1, 0, N - 1, M - 1);

			max_area = max(max_area, sum1 * sum2 * sum3);
		}

	for (int i = 0; i < N - 1; i++)
		for (int j = 0; j < M - 1; j++)
		{
			long long sum1 = get_sum(0, 0, N-1, j);
			long long sum2 = get_sum(0, j + 1, i, M - 1);
			long long sum3 = get_sum(i + 1, j+1, N - 1, M - 1);

			max_area = max(max_area, sum1 * sum2 * sum3);
		}

	for (int i = 0; i < N - 1; i++)
		for (int j = 0; j < M - 1; j++)
		{
			long long sum1 = get_sum(0, 0, i, M-1);
			long long sum2 = get_sum(i+1, 0, N-1, j);
			long long sum3 = get_sum(i + 1, j+1, N - 1, M - 1);

			max_area = max(max_area, sum1 * sum2 * sum3);
		}

	for (int i = 0; i < N - 1; i++)
		for (int j = 0; j < M - 1; j++)
		{
			long long sum1 = get_sum(0, 0, i, j);
			long long sum2 = get_sum(0, j + 1, N-1, M - 1);
			long long sum3 = get_sum(i + 1, 0, N-1, j);

			max_area = max(max_area, sum1 * sum2 * sum3);
		}
	
	printf("%lld\n", max_area);

}

