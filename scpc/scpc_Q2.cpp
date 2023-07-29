/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>


#define MAXNUM 1000001

using namespace std;


int Answer;

int straw_spot[MAXNUM];


int main(int argc, char** argv)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */

	 // freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////

		int N, D;
		cin >> N >> D;

		memset(straw_spot, 0, MAXNUM * sizeof(int));

		for (int i = 0; i < N; i++)
		{
			int spot;
			cin >> spot;

			straw_spot[i] = spot;
		}

		sort(straw_spot, straw_spot + N);

		if (straw_spot[0] >= 0)
		{
			for (int i = N - 1; i >= 0; i--) {

				if (D >= straw_spot[i]) {
					Answer = i + 1;
					break;
				}
			}

		}
		else if (straw_spot[N - 1] < 0)
		{
			for (int i = 0; i < N; i++) {

				if (D >= abs(straw_spot[i])) {
					Answer = N - i;
					break;
				}

			}

		}
		else
		{
			int border_positive_idx = 0;
			int border_negative_idx = 0;

			for(int i=0;i<N;i++)
				if (straw_spot[i] < 0 && straw_spot[i + 1] >= 0) {
					border_negative_idx = i;
					border_positive_idx = i + 1;
					break;
				}

			int remained_distance = 0;
			for (int i = 0; i < border_positive_idx; i++) {


				if (D >= abs(straw_spot[i]))
				{
					int result = 0;

					remained_distance = D - abs(straw_spot[i]);
					result += (border_negative_idx - i+1);
					
					for (int j = N - 1; j >= border_positive_idx; j--) {
						if (remained_distance >= straw_spot[j] - straw_spot[i])
						{
							remained_distance -= (straw_spot[j] - straw_spot[i]);
							result += (j - border_positive_idx + 1);
							break;
						}

					}


					if (Answer < result)
						Answer = result;

					if (straw_spot[i] == straw_spot[i + 1])
						for (int k = i + 1;; k++)
							if (straw_spot[i] == straw_spot[k])
							{
								i++;
							}
							else
								break;

				}



			}


		}


		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).
		printf("Case #%d\n",test_case + 1);
		printf("%d\n", Answer);
	}

	return 0;//Your program should return 0 on normal termination.
}