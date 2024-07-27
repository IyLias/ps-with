/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int Answer;
vector<int> seq;

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
        cin.tie(NULL);
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
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		int N,S,E;
		cin >> N >> S >> E;
		seq.resize(N+1);

		for(int i=0;i<N;i++)
		   cin >> seq[i];


		vector<vector<long long>> min_cost(N, vector<long long>(2,0));

		min_cost[0][0] = (seq[0] == 1) ? E : 0;
		min_cost[0][1] = 0;
		
		for(int i=1;i<N;i++){
		   min_cost[i][0] = min(min_cost[i-1][0],min_cost[i-1][1]) + (seq[i]==1?E:0);
		   min_cost[i][1] = min_cost[i-1][1] + (seq[i]==0?S:0);
		}

		long long result = min(min_cost[N-1][0],min_cost[N-1][1]);
		
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << result << endl;
	

	return 0;//Your program should return 0 on normal termination.
}
