#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAXNUM	32001

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> ans;
vector<int> connected;
priority_queue<int,vector<int>,greater<int>> pq;


void dfs(int v){
  visited[v] = true;
  for (int u : adj[v]){
     if (!visited[u])
	 dfs(u);
  }
  
  ans.push_back(v);
}

void topological_sort(int N){
  ans.clear();

  for (int i=1;i<=N;i++)
     if(connected[i] == 0)
	pq.push(i);  

  while(!pq.empty()){
     int problem = pq.top();
     cout << "pq top: " << problem << endl;
     pq.pop();
     ans.push_back(problem);

     for(int u : adj[problem])
     	if(--connected[u] == 0)
	   pq.push(u);

  }

}

int main(){
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 
 int N,M;
 cin >> N >> M;

 adj.resize(N+1);
 connected.resize(N+1);

 for(int i=0;i<M;i++){
   int s1, s2;
   cin >> s1 >> s2;

   adj[s1].push_back(s2);
   connected[s2]++;
 }

 topological_sort(N);
 
 for(int i=0;i<N;i++)
    cout << ans[i] << " ";
 cout << endl;


 return 0;
}
