
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAXNUM	32001

using namespace std;

vector<vector<int>> adj;
vector<int> b_time;
vector<int> ans;
vector<int> connected;
queue<int> qq;


void topological_sort(int N){
  ans.clear();

  for (int i=1;i<=N;i++)
     if(connected[i] == 0){
	qq.push(i);  
        ans[i] = b_time[i];
     }

  while(!qq.empty()){
     int building = qq.front();
     cout << "queue top: " << building << endl;
     qq.pop();

     for(int u : adj[building]){
 
        ans[u] = max(ans[u], b_time[u] + ans[building]);

     	if(--connected[u] == 0)
	   qq.push(u);


     }

  }

}

int main(){
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 
 int N;
 cin >> N;
 
 adj.resize(N+1);
 connected.resize(N+1);
 b_time.resize(N+1);
 ans.resize(N+1);

 for(int i=1;i<=N;i++){
   int t; cin >> t;
   b_time[i] = t;
   while(1){
     int b;
     cin >> b;
     if(b == -1) break;
     adj[b].push_back(i);
     connected[i]++;
   }

 }

 topological_sort(N);
 
 for(int i=1;i<=N;i++)
    cout << ans[i] << " ";
 cout << endl;


 return 0;
}
