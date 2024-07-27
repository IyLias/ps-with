#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int Answer;

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
		string str;
		cin >> str;

		for (int i=0;i< str.length();i++){
		   if(i<str.length()-1 && str[i]=='A' && str[i]==str[i+1])
			Answer+=2;

		   if(i<str.length()-2 && str[i]=='A' && str[i+1]=='B' && str[i+2]=='A')
			Answer+=1;

		}
		   

		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
 		//cout << str << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
