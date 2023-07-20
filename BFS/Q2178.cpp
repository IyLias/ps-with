#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <string>

using namespace std;

int N, M;
int maze_map[100][100];

bool visited[100][100];

int dir[4][2] = { {0,-1},{-1,0},{0,1},{1,0} };

void search() {

    queue<pair<int, int>> que;
    que.push({ 0,0 });
    visited[0][0] = true;

    while (!que.empty()) {

        int r = que.front().first;
        int c = que.front().second;
        que.pop();

        for (int i = 0; i < 4; i++) {
            int rr = r + dir[i][0], rc = c + dir[i][1];
            if (rr >= 0 && rr < N && rc >= 0 && rc < M)
                if (maze_map[rr][rc] != 0) {

                    if (visited[rr][rc] == false) {
                        que.push({ rr,rc });
                        visited[rr][rc] = true;
                        maze_map[rr][rc] += maze_map[r][c];
                    }
                    /*else
                        if (maze_map[rr][rc] > maze_map[r][c] + 1)
                            maze_map[rr][rc] = maze_map[r][c] + 1;*/
                }

        }

    }

}

int main()
{
    scanf("%d %d", &N, &M);
    
    for (int i = 0; i < N; i++) {
        string a;
        cin >> a;

        for (int j = 0; j < M; j++) {
            maze_map[i][j] = a[j] - '0';
        }
    }

    search();

    cout << maze_map[N - 1][M - 1] << endl;
}

