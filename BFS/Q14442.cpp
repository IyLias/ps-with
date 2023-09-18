#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <string>
#include <set>

#define MAXNUM	1001

using namespace std;

int mmap[MAXNUM][MAXNUM];
bool visited[MAXNUM][MAXNUM][11];

int dir[4][2] = { {0,-1},{-1,0},{0,1},{1,0} };

typedef struct node {
	int r;
	int c;
	int length;
	int is_broken;

};

int search(int N, int M,int K) {


	queue<node> que;

	visited[0][0][0] = true;
	que.push({ 0,0,1,false });
	while (!que.empty()) {

		node cur_node = que.front();
		que.pop();

		if (cur_node.r == N - 1 && cur_node.c == M - 1)
			return cur_node.length;

		for (int i = 0; i < 4; i++)
		{
			int cr = cur_node.r + dir[i][0];
			int cc = cur_node.c + dir[i][1];

			if (cr < 0 || cr >= N || cc < 0 || cc >= M) continue;

			if (mmap[cr][cc] == 1 && cur_node.is_broken < K && !visited[cr][cc][cur_node.is_broken+1])
			{
				visited[cr][cc][cur_node.is_broken+1] = true;
				que.push({ cr,cc,cur_node.length + 1,cur_node.is_broken + 1 });
			}
			else if (mmap[cr][cc] == 0 && !visited[cr][cc][cur_node.is_broken]) {
				visited[cr][cc][cur_node.is_broken] = true;
				que.push({ cr,cc,cur_node.length + 1,cur_node.is_broken });
			}

		}

	}


	return -1;
}

int main()
{
	int N, M, K;
	scanf("%d %d %d", &N, &M,&K);

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;

		for (int j = 0; j < s.size(); j++)
			mmap[i][j] = s[j] - '0';
	}


	cout << search(N, M, K) << endl;

}
