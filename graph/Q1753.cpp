#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>


#define INF 1123456789
#define MAXNUM  20000

using namespace std;

vector<pair<int,int>> graph[MAXNUM+1];
int dist[MAXNUM+1];

priority_queue<pair<int,int>> pq;

void dijkstra(int V,int E,int start){

  for(int i=1;i<=V;i++){
    if(i != start)
        dist[i] = INF;
  }
  pq.push(make_pair(0,start));

  while(!pq.empty()){
      int curDist = -pq.top().first;
      int curNode = pq.top().second;
      pq.pop();

      for(int i=0;i<graph[curNode].size();i++){

          int nextNode = graph[curNode][i].first;
          int nextDist = graph[curNode][i].second;

          if(curDist+nextDist < dist[nextNode]){ // find connected nodes with curNode
            dist[nextNode] = curDist + nextDist;
            pq.push(make_pair(-dist[nextNode],nextNode));
          }
      }
  }

}


int main(){

  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int V,E;
  cin >> V >> E;

  int startNode;
  cin >> startNode;

  for(int i=0;i<E;i++){
      int u,v,w;
      cin >> u >> v >> w;
      graph[u].push_back(make_pair(v,w));
  }

  dijkstra(V,E,startNode);

  for(int i=1;i<=V;i++)
    if(dist[i] == INF)
        cout << "INF" << '\n';
    else
        cout << dist[i] << '\n';

  return 0;
}