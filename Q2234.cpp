#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int room_num = 0;
int room_largest = 0;

vector<int> rooms;
vector<vector<int>> visited(50, vector<int>(50, 0));
vector<vector<int>> castle_map(50, vector<int>(50));


int dir[4][2] = { {0,-1},{-1,0},{0,1},{1,0} };

void search(const vector<vector<int>> &castle_map, int r,int c) {

    for(int i=r;i< castle_map.size();i++)
        for (int j = c; j < castle_map[i].size(); j++)
        {
            int room = castle_map[i][j];
            visited[i][j] = true;

            bool stop_flag = true;
            for (int k = 0; k < 4; k++)
            {
                if (!(room & (1 << k)) && !visited[i + dir[k][0]][j + dir[k][1]])
                {
                    stop_flag = false;
                    search(castle_map, i + dir[k][0], j + dir[k][1]);


                }

            }

            if (stop_flag == true)
                return;


        }

}


int bfs_search(int r,int c) {

    int area = 1;

    queue < pair<int, int>> que;
    que.push(make_pair(r, c));
    
    visited[r][c] = room_num;

    while (!que.empty()) {

        int cr = que.front().first;
        int cc = que.front().second;
        que.pop();

        int room = castle_map[cr][cc];

        for (int k = 0; k < 4; k++)
        {
            if(cr + dir[k][0]>=0 && cr + dir[k][0] < M && cc + dir[k][1] >= 0 && cc + dir[k][1] < N)
                if (!(room & (1 << k)) && !visited[cr + dir[k][0]][cc + dir[k][1]])
                {
                    visited[cr + dir[k][0]][cc + dir[k][1]] = room_num;
                    area++;
                    que.push({ cr + dir[k][0],cc + dir[k][1] });
                }

        }

    }

    return area;
}



int main()
{
    scanf_s("%d %d", &N, &M);

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            scanf_s("%d", &castle_map[i][j]);


    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            if (visited[i][j] == 0) {
                room_num++;
                rooms.push_back(bfs_search(i, j));
                if (rooms.back() > room_largest)
                    room_largest = rooms.back();
            }


    cout << room_num << endl;
    cout << room_largest << endl;
    

}


