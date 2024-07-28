#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj;
vector<int> b_time;
vector<int> connected;
vector<int> ans;
queue<int> q;

void search(int N){

   for(int i=1;i<=N;i++){
      if(connected[i] == 0){
	 q.push(i);
	 ans[i] = b_time[i];
      }
   } 
	
   while(!q.empty()){
      int building = q.front();
      q.pop();

      for(int next_one : adj[building]){
	
	 ans[next_one] = max(ans[next_one], ans[building] + b_time[next_one]);
	 if(--connected[next_one] == 0)
	    q.push(next_one);
      }


   }


}


int main(){

 ios_base::sync_with_stdio(false);
 cin.tie(NULL);

 int T;
 cin >> T;

 for (int i=0;i<T;i++){
   int N,K;
   cin >> N >> K;

   adj.resize(N+1);
   b_time.resize(N+1);
   connected.resize(N+1);
   ans.resize(N+1);

   adj.clear(); b_time.clear(); connected.clear(); ans.clear();

   for(int b=1;b<=N;b++)
      cin >> b_time[b];

   for(int k=0;k<K;k++){
      int s1,s2;
      cin >> s1 >> s2;

      adj[s1].push_back(s2);
      connected[s2]++;
   }
   
   int W;
   cin >> W;

   search(N);

   cout << ans[W] << endl;
 }


 return 0;
}
