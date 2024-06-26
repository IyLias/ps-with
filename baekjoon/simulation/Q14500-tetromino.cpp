﻿#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <string>

#define MAXNUM	500

int board[MAXNUM][MAXNUM];

int all_patterns[][4][4] = {
	{{1,1,1,1},{0,0,0,0},{0,0,0,0},{0,0,0,0}},
	{{0,0,0,0},{1,1,1,1},{0,0,0,0},{0,0,0,0}},
	{{0,0,0,0},{0,0,0,0},{1,1,1,1},{0,0,0,0}},
	{{0,0,0,0},{0,0,0,0},{0,0,0,0},{1,1,1,1}}, 

	{{1,0,0,0},{1,0,0,0},{1,0,0,0},{1,0,0,0}},
	{{0,1,0,0},{0,1,0,0},{0,1,0,0},{0,1,0,0}},
	{{0,0,1,0},{0,0,1,0},{0,0,1,0},{0,0,1,0}},
	{{0,0,0,1},{0,0,0,1},{0,0,0,1},{0,0,0,1}},
	
	{{1,1,0,0},{1,1,0,0},{0,0,0,0},{0,0,0,0}},
	{{0,1,1,0},{0,1,1,0},{0,0,0,0},{0,0,0,0}},
	{{0,0,1,1},{0,0,1,1},{0,0,0,0},{0,0,0,0}},
	{{0,0,0,0},{1,1,0,0},{1,1,0,0},{0,0,0,0}},
	{{0,0,0,0},{0,1,1,0},{0,1,1,0},{0,0,0,0}},
	{{0,0,0,0},{0,0,1,1},{0,0,1,1},{0,0,0,0}},
	{{0,0,0,0},{0,0,0,0},{1,1,0,0},{1,1,0,0}},
	{{0,0,0,0},{0,0,0,0},{0,1,1,0},{0,1,1,0}},
	{{0,0,0,0},{0,0,0,0},{0,0,1,1},{0,0,1,1}},
	
	
	{{1,0,0,0},{1,0,0,0},{1,1,0,0},{0,0,0,0}},
	{{0,1,0,0},{0,1,0,0},{0,1,1,0},{0,0,0,0}},
	{{0,0,1,0},{0,0,1,0},{0,0,1,1},{0,0,0,0}},
	{{0,0,0,0},{1,0,0,0},{1,0,0,0},{1,1,0,0}},
	{{0,0,0,0},{0,1,0,0},{0,1,0,0},{0,1,1,0}},
	{{0,0,0,0},{0,0,1,0},{0,0,1,0},{0,0,1,1}},
	
	{{1,1,1,0},{1,0,0,0},{0,0,0,0},{0,0,0,0}},
	{{0,1,1,1},{0,1,0,0},{0,0,0,0},{0,0,0,0}},
	{{0,0,0,0},{1,1,1,0},{1,0,0,0},{0,0,0,0}},
	{{0,0,0,0},{0,1,1,1},{0,1,0,0},{0,0,0,0}},
	{{0,0,0,0},{0,0,0,0},{1,1,1,0},{1,0,0,0}},
	{{0,0,0,0},{0,0,0,0},{0,1,1,1},{0,1,0,0}},
	
	{{1,1,0,0},{0,1,0,0},{0,1,0,0},{0,0,0,0}},
	{{0,1,1,0},{0,0,1,0},{0,0,1,0},{0,0,0,0}},
	{{0,0,1,1},{0,0,0,1},{0,0,0,1},{0,0,0,0}},
	{{0,0,0,0},{1,1,0,0},{0,1,0,0},{0,1,0,0}},
	{{0,0,0,0},{0,1,1,0},{0,0,1,0},{0,0,1,0}},
	{{0,0,0,0},{0,0,1,1},{0,0,0,1},{0,0,0,1}},

	{{0,0,1,0},{1,1,1,0},{0,0,0,0},{0,0,0,0}},
	{{0,0,0,1},{0,1,1,1},{0,0,0,0},{0,0,0,0}},
	{{0,0,0,0},{0,0,1,0},{1,1,1,0},{0,0,0,0}},
	{{0,0,0,0},{0,0,0,1},{0,1,1,1},{0,0,0,0}},
	{{0,0,0,0},{0,0,0,0},{0,0,1,0},{1,1,1,0}},
	{{0,0,0,0},{0,0,0,0},{0,0,0,1},{0,1,1,1}},
	
	{{0,1,0,0},{0,1,0,0},{1,1,0,0},{0,0,0,0}},
	{{0,0,1,0},{0,0,1,0},{0,1,1,0},{0,0,0,0}},
	{{0,0,0,1},{0,0,0,1},{0,0,1,1},{0,0,0,0}},
	{{0,0,0,0},{0,1,0,0},{0,1,0,0},{1,1,0,0}},
	{{0,0,0,0},{0,0,1,0},{0,0,1,0},{0,1,1,0}},
	{{0,0,0,0},{0,0,0,1},{0,0,0,1},{0,0,1,1}},

	{{1,0,0,0},{1,1,1,0},{0,0,0,0},{0,0,0,0}},
	{{0,1,0,0},{0,1,1,1},{0,0,0,0},{0,0,0,0}},
	{{0,0,0,0},{1,0,0,0},{1,1,1,0},{0,0,0,0}},
	{{0,0,0,0},{0,1,0,0},{0,1,1,1},{0,0,0,0}},
	{{0,0,0,0},{0,0,0,0},{1,0,0,0},{1,1,1,0}},
	{{0,0,0,0},{0,0,0,0},{0,1,0,0},{0,1,1,1}},

	{{1,1,0,0},{1,0,0,0},{1,0,0,0},{0,0,0,0}},
	{{0,1,1,0},{0,1,0,0},{0,1,0,0},{0,0,0,0}},
	{{0,0,1,1},{0,0,1,0},{0,0,1,0},{0,0,0,0}},
	{{0,0,0,0},{1,1,0,0},{1,0,0,0},{1,0,0,0}},
	{{0,0,0,0},{0,1,1,0},{0,1,0,0},{0,1,0,0}},
	{{0,0,0,0},{0,0,1,1},{0,0,1,0},{0,0,1,0}},


	{{1,1,1,0},{0,0,1,0},{0,0,0,0},{0,0,0,0}},
	{{0,1,1,1},{0,0,0,1},{0,0,0,0},{0,0,0,0}},
	{{0,0,0,0},{1,1,1,0},{0,0,1,0},{0,0,0,0}},
	{{0,0,0,0},{0,1,1,1},{0,0,0,1},{0,0,0,0}},
	{{0,0,0,0},{0,0,0,0},{1,1,1,0},{0,0,1,0}},
	{{0,0,0,0},{0,0,0,0},{0,1,1,1},{0,0,0,1}},

	///


	{{1,0,0,0},{1,1,0,0},{0,1,0,0},{0,0,0,0}},
	{{0,1,0,0},{0,1,1,0},{0,0,1,0},{0,0,0,0}},
	{{0,0,1,0},{0,0,1,1},{0,0,0,1},{0,0,0,0}},
	{{0,0,0,0},{1,0,0,0},{1,1,0,0},{0,1,0,0}},
	{{0,0,0,0},{0,1,0,0},{0,1,1,0},{0,0,1,0}},
	{{0,0,0,0},{0,0,1,0},{0,0,1,1},{0,0,0,1}},

	{{0,1,1,0},{1,1,0,0},{0,0,0,0},{0,0,0,0}},
	{{0,0,1,1},{0,1,1,0},{0,0,0,0},{0,0,0,0}},
	{{0,0,0,0},{0,1,1,0},{1,1,0,0},{0,0,0,0}},
	{{0,0,0,0},{0,0,1,1},{0,1,1,0},{0,0,0,0}},
	{{0,0,0,0},{0,0,0,0},{0,1,1,0},{1,1,0,0}},
	{{0,0,0,0},{0,0,0,0},{0,0,1,1},{0,1,1,0}},
	
	{ {0,1,0,0},{1,1,0,0},{1,0,0,0},{0,0,0,0} },
	{ {0,0,1,0},{0,1,1,0},{0,1,0,0},{0,0,0,0} },
	{ {0,0,0,1},{0,0,1,1},{0,0,1,0},{0,0,0,0} },
	{ {0,0,0,0},{0,1,0,0},{1,1,0,0},{1,0,0,0} },
	{ {0,0,0,0},{0,0,1,0},{0,1,1,0},{0,1,0,0} },
	{ {0,0,0,0},{0,0,0,1},{0,0,1,1},{0,0,1,0} },


	{ {1,1,0,0},{0,1,1,0},{0,0,0,0},{0,0,0,0} },
	{ {0,1,1,0},{0,0,1,1},{0,0,0,0},{0,0,0,0} },
	{ {0,0,0,0},{1,1,0,0},{0,1,1,0},{0,0,0,0} },
	{ {0,0,0,0},{0,1,1,0},{0,0,1,1},{0,0,0,0} },
	{ {0,0,0,0},{0,0,0,0},{1,1,0,0},{0,1,1,0} },
	{ {0,0,0,0},{0,0,0,0},{0,1,1,0},{0,0,1,1} },

	////// 
	
	{ {1,1,1,0},{0,1,0,0},{0,0,0,0},{0,0,0,0} },
	{ {0,1,1,1},{0,0,1,0},{0,0,0,0},{0,0,0,0} },
	{ {0,0,0,0},{1,1,1,0},{0,1,0,0},{0,0,0,0} },
	{ {0,0,0,0},{0,1,1,1},{0,0,1,0},{0,0,0,0} },
	{ {0,0,0,0},{0,0,0,0},{1,1,1,0},{0,1,0,0} },
	{ {0,0,0,0},{0,0,0,0},{0,1,1,1},{0,0,1,0} },

	{ {0,1,0,0},{1,1,0,0},{0,1,0,0},{0,0,0,0} },
	{ {0,0,1,0},{0,1,1,0},{0,0,1,0},{0,0,0,0} },
	{ {0,0,0,1},{0,0,1,1},{0,0,0,1},{0,0,0,0} },
	{ {0,0,0,0},{0,1,0,0},{1,1,0,0},{0,1,0,0} },
	{ {0,0,0,0},{0,0,1,0},{0,1,1,0},{0,0,1,0} },
	{ {0,0,0,0},{0,0,0,1},{0,0,1,1},{0,0,0,1} },

	{ {0,1,0,0},{1,1,1,0},{0,0,0,0},{0,0,0,0} },
	{ {0,0,1,0},{0,1,1,1},{0,0,0,0},{0,0,0,0} },
	{ {0,0,0,0},{0,1,0,0},{1,1,1,0},{0,0,0,0} },
	{ {0,0,0,0},{0,0,1,0},{0,1,1,1},{0,0,0,0} },
	{ {0,0,0,0},{0,0,0,0},{0,1,0,0},{1,1,1,0} },
	{ {0,0,0,0},{0,0,0,0},{0,0,1,0},{0,1,1,1} },


	{ {1,0,0,0},{1,1,0,0},{1,0,0,0},{0,0,0,0} },
	{ {0,1,0,0},{0,1,1,0},{0,1,0,0},{0,0,0,0} },
	{ {0,0,1,0},{0,0,1,1},{0,0,1,0},{0,0,0,0} },
	{ {0,0,0,0},{1,0,0,0},{1,1,0,0},{1,0,0,0} },
	{ {0,0,0,0},{0,1,0,0},{0,1,1,0},{0,1,0,0} },
	{ {0,0,0,0},{0,0,1,0},{0,0,1,1},{0,0,1,0} },

};


using namespace std;

int main()
{
	int N,M;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &board[i][j]);


	int max_value = 0;
	for(int i=0;i+4<=N;i++)
		for (int j = 0; j + 4 <= M; j++)
		{
			for (int p = 0; p < 113; p++) {
				int current_value = 0;
				for (int n = i; n < i + 4; n++)
					for (int m = j; m < j + 4; m++)
					{
						if (all_patterns[p][n-i][m-j] == 1)
							current_value += board[n][m];

					}

				if (max_value < current_value)
					max_value = current_value;
			}
		}


	printf("%d\n",max_value);
}



