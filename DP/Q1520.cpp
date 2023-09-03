#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <cstring>
#include <set>

#define MAXNUM	500

typedef long long ll;

int mmap[MAXNUM][MAXNUM];
int M,N;

ll dp[MAXNUM][MAXNUM];

using namespace std;

int dir[4][2] = { {0,-1},{-1,0},{0,1},{1,0} };

ll search(int r,int c) {

    if (r == M - 1 && c == N - 1) {
        return 1;
    }
    if (dp[r][c] != -1)
        return dp[r][c];

    // now visited [r,c]
    dp[r][c] = 0; 
    
    // 4 directions.. search downhill
    for (int i = 0; i < 4; i++)
    {
        int cr = r + dir[i][0], cc = c + dir[i][1];
        if (cr >= 0 && cr < M && cc >= 0 && cc < N)
            if (mmap[r][c] > mmap[cr][cc])
            {
                dp[r][c] += search(cr, cc);
            }

    }

    return dp[r][c];
}



int main()
{
    scanf("%d %d", &M, &N);

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++) {
            scanf("%d", &mmap[i][j]);
            dp[i][j] = -1;
        }

    printf("%lld\n", search(0, 0));

    return 0;
}

