#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <string>

using namespace std;

int visited[1000001];

int main()
{
    int F, S, G, U, D;
    scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);

    queue<pair<int, int>> que;
    que.push({ S, 0 });
    visited[S] = true;

    if ((S > G && D == 0) || (S < G && U == 0)) {
        printf("use the stairs\n");
        return 0;
    }


    while (!que.empty()) {

        int current_floor = que.front().first;
        int current_move_times = que.front().second;
        
        que.pop();

        if (current_floor == G)
        {
            printf("%d\n", current_move_times);
            return 0;
        }

        if (current_floor + U <= F && !visited[current_floor + U]) {
            que.push({ current_floor + U, current_move_times + 1 });
            visited[current_floor+U] = true;
        }

        if (current_floor - D >= 1 && !visited[current_floor - D]) {
            que.push({ current_floor - D, current_move_times + 1 });
            visited[current_floor-D] = true;
        }
    }

    printf("use the stairs\n");
    return 0;
}
