#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <cstring>
#include <set>

#define MAXNUM  100001

int A[MAXNUM];

using namespace std;

bool search(int first,int last, int target) {

	int start = first;
	int end = last;

	while (start <= end) {
		int mid = (start + end) / 2;
		if (A[mid] < target)
			start = mid + 1;
		else if (A[mid] > target)
			end = mid - 1;
		else
			return true;
	}

	return false;
}



int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	sort(A, A + N);

	int M;
	scanf("%d", &M);

	for (int i = 0; i < M; i++) {

		int num;
		scanf("%d", &num);

		bool result = search(0,N-1,num);
		printf("%d\n", result == true ? 1 : 0);
	}


	return 0;
}

