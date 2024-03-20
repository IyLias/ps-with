#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <queue>
#include <iostream>
#include <string>

using namespace std;

int N;
int board[4][4];

vector<string> game_scenarios;

// return max value
int simulate_move(char direction, int(&current_board)[4][4]) {

	int score = 0;

	switch (direction) {

	// up
	case 'U':
		for (int j = 0; j < 4; j++) {
			int stack_idx = -1;
			bool is_collided[20];
			for (int k = 0; k < 4; k++)
				is_collided[k] = false;

			for (int i = 0; i < 4; i++)
			{
				if (current_board[i][j] != 0)
				{
					if (stack_idx + 1 != 0 && current_board[stack_idx][j] == current_board[i][j] && is_collided[stack_idx] == false)
					{
						current_board[stack_idx][j] *= 2;
						score += current_board[stack_idx][j];
						current_board[i][j] = 0;
						is_collided[stack_idx] = true;
					}
					else
					{
						stack_idx++;
						current_board[stack_idx][j] = current_board[i][j];
						if (i != stack_idx)
							current_board[i][j] = 0;
					}

				}

			}

		}
		break;

	// right
	case 'R':
		for (int i = 0; i < 4; i++) {
			int stack_idx = 4;
			bool is_collided[20];
			for (int k = 0; k < 4; k++)
				is_collided[k] = false;

			for (int j = 3; j >= 0; j--)
			{
				if (current_board[i][j] != 0)
				{
					if (stack_idx - 1 != 3 && current_board[i][stack_idx] == current_board[i][j] && is_collided[stack_idx] == false)
					{
						current_board[i][stack_idx] *= 2;
						score += current_board[i][stack_idx];
						current_board[i][j] = 0;
						is_collided[stack_idx] = true;
					}
					else {
						stack_idx--;
						current_board[i][stack_idx] = current_board[i][j];
						if (j != stack_idx)
							current_board[i][j] = 0;
					}

				}

			}
		}

		break;

	// down
	case 'D':

		for (int j = 0; j < 4; j++) {
			int stack_idx = 4;
			bool is_collided[20];
			for (int k = 0; k < 4; k++)
				is_collided[k] = false;

			for (int i = 3; i >= 0; i--)
			{
				if (current_board[i][j] != 0)
				{
					if (stack_idx - 1 != 3 && current_board[stack_idx][j] == current_board[i][j] && is_collided[stack_idx] == false)
					{
						current_board[stack_idx][j] *= 2;
						score += current_board[stack_idx][j];
						current_board[i][j] = 0;
						is_collided[stack_idx] = true;
					}
					else {
						stack_idx--;
						current_board[stack_idx][j] = current_board[i][j];
						if (i != stack_idx)
							current_board[i][j] = 0;
					}

				}

			}

		}
		break;


	// left
	case 'L':
		for (int i = 0; i < 4; i++) {
			int stack_idx = -1;
			bool is_collided[20];
			for (int k = 0; k < 4; k++)
				is_collided[k] = false;

			for (int j = 0; j < 4; j++)
			{
				if (current_board[i][j] != 0)
				{

					if (stack_idx + 1 != 0 && current_board[i][stack_idx] == current_board[i][j] && is_collided[stack_idx] == false)
					{
						current_board[i][stack_idx] *= 2;
						score += current_board[i][stack_idx];
						current_board[i][j] = 0;
						is_collided[stack_idx] = true;
					}
					else {
						stack_idx++;
						current_board[i][stack_idx] = current_board[i][j];
						if (j != stack_idx)
							current_board[i][j] = 0;
					}



				}

			}

		}
		break;
	}


	return score;
}


void print_board(int(current_board)[4][4])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf("%d ", current_board[i][j]);
		printf("\n");
	}

	printf("\n\n");
}

//int search(int times, int max_value, int(current_board)[20][20]) {
//
//	if (times == 0)
//		return max_value;
//
//	int max_result = 0;
//	int temp_board[20][20];
//	for (int i = 0; i < 4; i++) {
//
//		for (int j = 0; j < N; j++)
//			for (int k = 0; k < N; k++)
//				temp_board[j][k] = current_board[j][k];
//
//		int value = simulate_move(i, temp_board);
//		int result = search(times - 1, value, temp_board);
//
//		if (result > max_result) max_result = result;
//	}
//
//	return max_result;
//}


int simulate_game(int(current_board)[4][4]) {

	int score = 0;
	int game_board[4][4];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			game_board[i][j] = current_board[i][j];

	for (string scenario : game_scenarios) {

		char direction = scenario[0];

		score += simulate_move(direction,game_board);
		
		int new_tile_value = scenario[1] - '0';
		int new_tile_r = scenario[2] - '0'; int new_tile_c = scenario[3]-'0';
		game_board[new_tile_r][new_tile_c] = new_tile_value;
 	}

	return score;
}



int main()
{
	int first_score;
	scanf("%d", &first_score);

	string game_scenario;
	cin >> game_scenario;
	for (int i = 0; i < game_scenario.length(); i++) {
		string scenario = game_scenario.substr(i, 4);
		game_scenarios.push_back(scenario);
		i += 3;
	}

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			scanf("%d", &board[i][j]);

	int total_score = first_score;
	total_score += simulate_game(board);
	
	printf("%d\n", total_score);

	return 0;
}

