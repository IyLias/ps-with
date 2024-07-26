#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

#define MAXNUM	32001

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> ans;

void dfs(int v){
  visited[v] = true;
  for (int u : adj[v]){
     if (!visited[u])
	 dfs(u);
  }
  
  ans.push_back(v);
}

void topological_sort(int N){
  visited.assign(N+1, false);
  ans.clear();
  for (int i=1;i<=N;i++){
     if (!visited[i])
	dfs(i);
  }

  reverse(ans.begin(),ans.end());  
}

int main(){
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 
 int N,M;
 cin >> N >> M;

 adj.resize(N+1);

 for(int i=0;i<M;i++){
   int s1, s2;
   cin >> s1 >> s2;

   adj[s1].push_back(s2);
 }

 topological_sort(N);
 
 for(int i=0;i<N;i++)
    cout << ans[i] << " ";
 cout << endl;


 return 0;
}
