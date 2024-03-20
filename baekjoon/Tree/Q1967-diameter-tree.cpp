#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <string>
#include <set>
#include <math.h>

#define MAXNUM	10001

using namespace std;

typedef pair<int, int> pii;

vector<pii> nodes[MAXNUM];
bool visited[MAXNUM];

int max_distance = 0;
int max_node = 0;

void dfs_search(int cur, int cur_distance) {

	if (visited[cur])
		return;


	if (cur_distance > max_distance) {
		max_distance = cur_distance;
		max_node = cur;
	}

	visited[cur] = true;

	for (int i = 0; i < (int)nodes[cur].size(); i++) {
		int nxt = nodes[cur][i].first;
		int dist = nodes[cur][i].second;
		dfs_search(nxt, cur_distance+dist);

	}


}

int main()
{
	int n;
	scanf("%d", &n);

	int cur, nxt, w;
	for (int i = 0; i < n - 1; i++) {

		scanf("%d %d %d", &cur, &nxt, &w);
		nodes[cur].push_back({ nxt,w });
		nodes[nxt].push_back({ cur,w });
	}

	dfs_search(1, 0);
	memset(visited,false,MAXNUM);
	
	//cout << max_node << " " << max_distance << endl;

	dfs_search(max_node, 0);

	cout << max_distance << endl;

	return 0;
}

