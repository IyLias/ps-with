#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

long long Answer;

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
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		int N;
		cin >> N;
		
		vector<int> weights(N);
                for(int i=0;i<N;i++)
		   cin >> weights[i];

		sort(weights.begin(), weights.end());

		vector<int> groupA,groupB,groupC,groupD;
		for(int i=0;i<N;i++){
		   if(i < N/4)
		     groupA.push_back(weights[i]);
		   else if(i < 2 * N/4)
		     groupB.push_back(weights[i]);
		   else if(i < 3*N/4)
		     groupC.push_back(weights[i]);
		   else 
		     groupD.push_back(weights[i]);
		}

		for(int i=0;i<N/4;i++){
		   Answer += (abs(groupD[i]-groupC[i])+abs(groupC[i]-groupB[i])+abs(groupB[i]-groupA[i])+abs(groupA[i]-groupD[i]));

		}

		
		
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
