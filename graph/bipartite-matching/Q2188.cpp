#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <string>
#include <set>
#include <math.h>

#define MAXNUM  1100

using namespace std;

vector<int> adj[MAXNUM];

int graphA[MAXNUM], graphB[MAXNUM];
bool visited[MAXNUM];


bool dfs(int from) {

    visited[from] = true;
    for (int i = 0; i < adj[from].size(); i++) {

        int to = adj[from][i];
        if (graphB[to] == -1 || (!visited[graphB[to]] && dfs(graphB[to]))) {
            graphA[from] = to;
            graphB[to] = from;
            return true;
        }

    }

    return false;
}


int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++) {
        int num;
        scanf("%d", &num);

        while (num--) {
            int to; scanf("%d", &to);
            adj[i].push_back(to);
        }

    }

    int match = 0;
    fill(&graphA[1], &graphA[N + 1], -1);
    fill(&graphB[1], &graphB[M + 1], -1);

    for (int i = 1; i <= N; i++) {
        if (graphA[i] == -1) {
            fill(&visited[1], &visited[N + 1], false);
            if (dfs(i)) match++;
        }

    }

    printf("%d\n", match);

}

