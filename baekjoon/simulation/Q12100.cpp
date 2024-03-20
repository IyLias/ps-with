#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <queue>
#include <iostream>
#include <string>

using namespace std;

int N;
int board[20][20];

// return max value
int simulate_move(int direction, int(&current_board)[20][20]){

	switch (direction) {


		// up
		case 0:
			for (int j = 0; j < N; j++) {
				int stack_idx = -1;
				bool is_collided[20];
				for (int k = 0; k < N; k++)
					is_collided[k] = false;

				for (int i = 0; i < N; i++)
				{
					if (current_board[i][j] != 0) 
					{
						if (stack_idx+1 == 0) {
							stack_idx++;
							current_board[stack_idx][j] = current_board[i][j];
							if(i != stack_idx)
								current_board[i][j] = 0;
						}
						else {

							if (current_board[stack_idx][j] == current_board[i][j] && is_collided[stack_idx] == false)
							{
								current_board[stack_idx][j] *= 2;
								current_board[i][j] = 0;
								is_collided [stack_idx] = true;
							}
							else {
								stack_idx++;
								current_board[stack_idx][j] = current_board[i][j];
								if(i != stack_idx)
									current_board[i][j] = 0;
							}

						}

					}

				}

			}
			break;

		// right
		case 1:
			for (int i = 0; i < N; i++) {
				int stack_idx = N;
				bool is_collided[20];
				for (int k = 0; k < N; k++)
					is_collided[k] = false;

				for (int j = N-1; j >= 0; j--)
				{
					if (current_board[i][j] != 0)
					{
						if (stack_idx-1 == N-1) {
							stack_idx--;
							current_board[i][stack_idx] = current_board[i][j];
							if(j != stack_idx)
								current_board[i][j] = 0;
						}
						else {

							if (current_board[i][stack_idx] == current_board[i][j] && is_collided[stack_idx] == false)
							{
								current_board[i][stack_idx] *= 2;
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

			}

			break;


		// down
		case 2:

			for (int j = 0; j < N; j++) {
				int stack_idx = N;
				bool is_collided[20];
				for (int k = 0; k < N; k++)
					is_collided[k] = false;

				for (int i = N-1; i >= 0; i--)
				{
					if (current_board[i][j] != 0)
					{
						if (stack_idx-1 == N-1) {
							stack_idx--;
							current_board[stack_idx][j] = current_board[i][j];
							if (i != stack_idx)
								current_board[i][j] = 0;
						}
						else {

							if (current_board[stack_idx][j] == current_board[i][j] && is_collided[stack_idx] == false)
							{
								current_board[stack_idx][j] *= 2;
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

			}

			break;





		// left
		case 3:
			for (int i = 0; i < N; i++) {
				int stack_idx = -1;
				bool is_collided[20];
				for (int k = 0; k < N; k++)
					is_collided[k] = false;

				for (int j = 0; j < N; j++)
				{
					if (current_board[i][j] != 0)
					{
						if (stack_idx+1 == 0) {
							stack_idx++;
							current_board[i][stack_idx] = current_board[i][j];
							if (j != stack_idx)
								current_board[i][j] = 0;
						}
						else {

							if (current_board[i][stack_idx] == current_board[i][j] && is_collided[stack_idx] == false)
							{
								current_board[i][stack_idx] *= 2;
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

			}

			break;

	}

	int max_value = 0;
	// find max value
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (current_board[i][j] > max_value)
				max_value = current_board[i][j];

	return max_value;
}


void print_board(int(current_board)[20][20])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf("%d ", current_board[i][j]);

		printf("\n");
	}

	printf("\n\n");
}

int search(int times,int max_value, int (current_board)[20][20]) {

	if (times == 0)
		return max_value;

	int max_result = 0;
	int temp_board[20][20];
	for (int i = 0; i < 4; i++) {

		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				temp_board[j][k] = current_board[j][k];

		int value = simulate_move(i,temp_board);
		print_board(temp_board);
		int result = search(times - 1, value, temp_board);
		
		if (result > max_result) max_result = result;
	}

	return max_result;
}


int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &board[i][j]);


	printf("%d\n",search(5,0,board));

	return 0;
}

