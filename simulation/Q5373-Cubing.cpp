#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <string>

#define UP		0
#define DOWN	1
#define FRONT	2
#define BACK	3
#define LEFT	4
#define RIGHT	5


using namespace std;

char cube[6][9] = { 

	{'w','w','w','w','w','w','w','w','w'}, // UP
	{'y','y','y','y','y','y','y','y','y'}, // DOWN
	{'r','r','r','r','r','r','r','r','r'}, // FRONT
	{'o','o','o','o','o','o','o','o','o'}, // BACK
	{'g','g','g','g','g','g','g','g','g'}, // LEFT
	{'b','b','b','b','b','b','b','b','b'}  // RIGHT

};


int cube_relation[6][4][4] = {

	{{RIGHT,0,1,2},{FRONT,0,1,2},{LEFT,0,1,2},{BACK,0,1,2}}, // UP
	{{FRONT,6,7,8},{RIGHT,6,7,8},{BACK,6,7,8},{LEFT,6,7,8}}, // DOWN
	{{UP,6,7,8},{RIGHT,0,3,6},{DOWN,2,1,0},{LEFT,8,5,2}}, // FRONT
	{{UP,2,1,0},{LEFT,0,3,6},{DOWN,6,7,8},{RIGHT,8,5,2}}, // BACK
	{{UP,0,3,6},{FRONT,0,3,6},{DOWN,0,3,6},{BACK,8,5,2}}, // LEFT
	{{UP,8,5,2},{BACK,0,3,6},{DOWN,8,5,2},{FRONT,8,5,2}} // RIGHT
	
};


void init_cube() {

	string color_list = "wyrogb";

	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 9; j++)
				cube[i][j] = color_list[i];

}


int get_side(char side) {

	switch (side) {

		case 'U':
			return 0;

		case 'D':
			return 1;

		case 'F':
			return 2;

		case 'B':
			return 3;

		case 'L':
			return 4;

		case 'R':
			return 5;

	}

}



void print_side(int side) {

	for (int i = 0; i < 9; i++) {
					
		printf("%c", cube[side][i]);
		if(i%3 == 2)
			printf("\n");
	}

}


void rotate(int side, bool is_clockwise) {

	int corner_points[4] = { 0,2,8,6 };
	int edge_points[4] = { 1,5,7,3 };

	if (is_clockwise) {
		
		// rotate target side 
		int corner_last_value = cube[side][corner_points[3]];
		int edge_last_value = cube[side][edge_points[3]];

		for (int i = 3; i > 0; i--) {
			cube[side][corner_points[i]] = cube[side][corner_points[i - 1]];

			cube[side][edge_points[i]] = cube[side][edge_points[i - 1]];
		}

		cube[side][corner_points[0]] = corner_last_value;
		cube[side][edge_points[0]] = edge_last_value;

		// rotate other 4 sides 
		int first_side_values[3] = { cube[cube_relation[side][0][0]][cube_relation[side][0][1]],cube[cube_relation[side][0][0]][cube_relation[side][0][2]],cube[cube_relation[side][0][0]][cube_relation[side][0][3]] };

		for (int i = 3; i >= 0; i--) {
			
			if (i != 0) {
				cube[cube_relation[side][(i + 1) % 4][0]][cube_relation[side][(i + 1) % 4][1]] = cube[cube_relation[side][i][0]][cube_relation[side][i][1]];
				cube[cube_relation[side][(i + 1) % 4][0]][cube_relation[side][(i + 1) % 4][2]] = cube[cube_relation[side][i][0]][cube_relation[side][i][2]];
				cube[cube_relation[side][(i + 1) % 4][0]][cube_relation[side][(i + 1) % 4][3]] = cube[cube_relation[side][i][0]][cube_relation[side][i][3]];
			}
			else
			{
				cube[cube_relation[side][(i + 1) % 4][0]][cube_relation[side][(i + 1) % 4][1]] = first_side_values[0];
				cube[cube_relation[side][(i + 1) % 4][0]][cube_relation[side][(i + 1) % 4][2]] = first_side_values[1];
				cube[cube_relation[side][(i + 1) % 4][0]][cube_relation[side][(i + 1) % 4][3]] = first_side_values[2];
			}

		}
	}
	else
	{
		// rotate target side 
		int corner_last_value = cube[side][corner_points[0]];
		int edge_last_value = cube[side][edge_points[0]];
		for (int i = 0; i < 3; i++)
		{
			cube[side][corner_points[i]] = cube[side][corner_points[i+1]];
			cube[side][edge_points[i]] = cube[side][edge_points[i + 1]];
		}

		cube[side][corner_points[3]] = corner_last_value;
		cube[side][edge_points[3]] = edge_last_value;

		// rotate other 4 sides 
		int first_side_values[3] = { cube[cube_relation[side][0][0]][cube_relation[side][0][1]],cube[cube_relation[side][0][0]][cube_relation[side][0][2]],cube[cube_relation[side][0][0]][cube_relation[side][0][3]] };

		for (int i = 0; i < 4; i++)
		{
			if (i != 3) {
				cube[cube_relation[side][i][0]][cube_relation[side][i][1]] = cube[cube_relation[side][i+1][0]][cube_relation[side][i+1][1]];
				cube[cube_relation[side][i][0]][cube_relation[side][i][2]] = cube[cube_relation[side][i+1][0]][cube_relation[side][i+1][2]];
				cube[cube_relation[side][i][0]][cube_relation[side][i][3]] = cube[cube_relation[side][i+1][0]][cube_relation[side][i+1][3]];
			}
			else
			{
				cube[cube_relation[side][3][0]][cube_relation[side][3][1]] = first_side_values[0];
				cube[cube_relation[side][3][0]][cube_relation[side][3][2]] = first_side_values[1];
				cube[cube_relation[side][3][0]][cube_relation[side][3][3]] = first_side_values[2];
			}

		}

	}



}



int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {

		int times;
		scanf("%d", &times);
		for (int i = 0; i < times; i++) {
			string rotate_how;
			cin >> rotate_how;

			int side = get_side(rotate_how[0]);
			bool is_clockwise = (rotate_how[1] == '+' ? true : false);
			rotate(side, is_clockwise);
		}

		print_side(UP);
		/*for (int i = 0; i < 6; i++) {
			print_side(i);
			printf("\n");
		}*/
		init_cube();
	}

	return 0;
}

