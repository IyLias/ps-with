#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>


#define INF 1123456789
#define MAXNUM  2000

using namespace std;

vector<pair<int,int>> graph[MAXNUM+1];
priority_queue<int> dist[MAXNUM+1];

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

void dijkstra(int K,int start){

  pq.push(make_pair(0,start));
  dist[1].push(0);

  while(!pq.empty()){
      int curDist = pq.top().first;
      int curNode = pq.top().second;
      pq.pop();

      for(auto i : graph[curNode]){ 

          int nextNode = i.first;
          int nextDist = i.second + curDist;

          if(dist[nextNode].size() < K){ 
            dist[nextNode].push(nextDist);
            pq.push({nextDist,nextNode});

          }else if(dist[nextNode].top() > nextDist){
              dist[nextNode].pop();
              dist[nextNode].push(nextDist);
              pq.push({nextDist,nextNode});
          }


      }
  }

}


int main(){

  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int N,M,K;
  cin >> N >> M >> K;

  for(int i=0;i<M;i++){
      int u,v,w;
      cin >> u >> v >> w;
      graph[u].push_back(make_pair(v,w)); 
  }

  dijkstra(K,1);

  for(int i=1;i<=N;i++){
      if(dist[i].size() < K)
        cout << "-1\n";
      else
        cout << dist[i].top() << '\n';

  }

  return 0;
}