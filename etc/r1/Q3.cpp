#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

int Answer;


void dfs(int N,int start, const vector<vector<int>>& network, vector<bool>& visited){
 
   stack<int> s;
   s.push(start);

   visited[start] = true;

   while(!s.empty()){
      int node = s.top();
      s.pop();

      for(int i=0;i<N;i++){
	 if(network[node][i]){
	    int neighbor = i;
	    if(!visited[neighbor]){
	       visited[neighbor] = true;
	       s.push(neighbor);
	    }
	 }
      }
   }

}

int count_component(int N,const vector<vector<int>>& network){

   int component=0;
   vector<bool> visited(N,false);   

   for(int i=0;i<N;i++){
      if(!visited[i]){
	dfs(N,i,network,visited);
	component++;
      }
   }
   
   cout << component << endl;
   return component;
}


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

		vector<vector<int>> network(N,vector<int>(N,0));
		vector<int> a(N+1,0),b(N+1,0);
		for(int i=0;i<N+1;i++){
		   cin >> a[i] >> b[i];

		   network[a[i]-1][b[i]-1]++;
		   network[b[i]-1][a[i]-1]++;
		}
	
		for(int i=0;i<N+1;i++)
		   for(int j=i+1;j<N+1;j++){
			vector<vector<int>> test_network = network;
				
			// edge1
			test_network[a[i]-1][b[i]-1]-=1;
			test_network[b[i]-1][a[i]-1]-=1;

			// edge2
			test_network[a[j]-1][b[j]-1]-=1;
			test_network[b[j]-1][a[j]-1]-=1;
			
			for(int m=0;m<N;m++){
			   for(int n=0;n<N;n++)
			      cout << test_network[m][n] << " ";
			   cout << endl;
			}

			if(count_component(N,test_network) != 1)
			   Answer++;
		   }
	

		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
