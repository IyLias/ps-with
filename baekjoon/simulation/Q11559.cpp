#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <string>


#define GAME_BOARD_ROW	12
#define GAME_BOARD_COL	6


using namespace std;


char game_board[GAME_BOARD_ROW][GAME_BOARD_COL]; // 12 x 6 
int dir[4][2] = { {0,-1},{-1,0},{0,1},{1,0} };



// 특정 칸에서 특정 색에서 출발하여 인접한 상하좌우를 BFS로 탐색하면서 연결된 푸요들을 터뜨린다.  
bool puyo_chain(int r,int c, char color) {


	queue<pair<pair<int, int>,char>> puyo_area;
	queue<pair<pair<int, int>,char>> puyo_result;

	bool visited[GAME_BOARD_ROW][GAME_BOARD_COL];
	for (int i = 0; i < GAME_BOARD_ROW; i++)
		for (int j = 0; j < GAME_BOARD_COL; j++)
			visited[i][j] = false;

	puyo_area.push({ {r,c},color });
	puyo_result.push({{ r,c }, color});
	visited[r][c] = true;

	while (!puyo_area.empty()) {

		int cur_r = puyo_area.front().first.first;
		int cur_c = puyo_area.front().first.second;
		char cur_color = puyo_area.front().second;

		puyo_area.pop();

		// search for 4 directions
		for (int i = 0; i < 4; i++) {
			int tar_r = cur_r + dir[i][0], tar_c = cur_c + dir[i][1];
			if(tar_r >= 0 && tar_r < GAME_BOARD_ROW && tar_c>=0 && tar_c<GAME_BOARD_COL)
				if (visited[tar_r][tar_c] == false && (game_board[tar_r][tar_c] == cur_color)) {
					visited[tar_r][tar_c] = true;
					puyo_area.push({ {tar_r,tar_c},cur_color });
					puyo_result.push({ {tar_r,tar_c},cur_color });
				}

		}

	}

	if (puyo_result.size() >= 4) {

		int result_size = puyo_result.size();
		// apply puyo panggggg
		for (int i = 0; i < result_size; i++)
		{
			int puyo_r = puyo_result.front().first.first;
			int puyo_c = puyo_result.front().first.second;

			puyo_result.pop();

			game_board[puyo_r][puyo_c] = '.';
		}

		return true;
	}
	
	return false;
}


// 터진 후 중력을 적용해 가장 바닥까지 뿌요가 떨어지게 보드를 배치 후 해당 보드 반환
void apply_gravity() {

	for (int i = 0; i < GAME_BOARD_COL; i++) {

		for (int j = GAME_BOARD_ROW - 2; j >= 0; j--) {
			int drop_spot = j;
			if (game_board[j][i] != '.') {
				for (int k = j + 1; k < GAME_BOARD_ROW; k++) {
					if (game_board[k][i] != '.')
					{
						drop_spot = k - 1;
						break;
					}

					if (k == GAME_BOARD_ROW - 1 && game_board[k][i] == '.')
						drop_spot = GAME_BOARD_ROW - 1;
				}

				char temp = game_board[j][i];
				game_board[j][i] = '.';
				game_board[drop_spot][i] = temp;

			}


		}


	}



}


// 현재 상태에서 게임보드를 입력으로 받아 딱 한 턴 연쇄 적용 후 모습의 보드를 리턴한다. 
int apply_turn() {

	bool puyo_chain_flag = false;
	for(int i=0;i<GAME_BOARD_ROW;i++)
		for(int j=0;j<GAME_BOARD_COL;j++){
			if (game_board[i][j] != '.') {
				bool puyo_result = puyo_chain(i,j,game_board[i][j]);
				if (puyo_result == true) {
					puyo_chain_flag = true;
				}

			}
		}

	apply_gravity();

	if (puyo_chain_flag == true)
		return 1;
	else
		return 0;

}


int play_game() {

	int num_chain = 0;

	while (true) {

		int current_turn_result = apply_turn();
		if (current_turn_result == 0) break;

		num_chain++;
	}

	return num_chain;
}




int main()
{
	for (int i = 0; i < GAME_BOARD_ROW; i++)
		scanf("%s", game_board[i]);

	//printf("now..\n\n");

	//for (int i = 0; i < 12; i++)
	//	printf("%s\n", game_board[i]);


	int game_result = play_game();
	printf("%d\n", game_result);

}
