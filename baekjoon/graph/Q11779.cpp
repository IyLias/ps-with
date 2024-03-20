#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>


#define INF 1123456789
#define MAXNUM  2000

using namespace std;

vector<pair<int,int>> graph[MAXNUM+1];

int route[MAXNUM+1];
vector<int> path;

int dist[MAXNUM+1];


priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

void dijkstra(int V,int E,int start){

  for(int i=1;i<=V;i++){
    if(i != start)
        dist[i] = INF;
  }
  pq.push(make_pair(0,start));

  while(!pq.empty()){
      int curDist = pq.top().first;
      int curNode = pq.top().second;
      pq.pop();

      if(curDist > dist[curNode]) continue;

      for(int i=0;i<graph[curNode].size();i++){

          int nextNode = graph[curNode][i].first;
          int nextDist = graph[curNode][i].second;

          if(curDist+nextDist < dist[nextNode]){ // find connected nodes with curNode
            route[nextNode] = curNode;
            dist[nextNode] = curDist + nextDist;
            pq.push(make_pair(dist[nextNode],nextNode));
          }
      }
  }

}

void findPath(int start,int end){

    int point = end;
    while(point){
        path.push_back(point);
        point = route[point];
    }

}


int main(){

  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int N,M;
  cin >> N >> M;

  for(int i=0;i<M;i++){
      int u,v,w;
      cin >> u >> v >> w;
      graph[u].push_back(make_pair(v,w)); 
  }

  int start,end;
  cin >> start >> end;

  dijkstra(N,M,start);

  cout << dist[end] << '\n';

  findPath(start,end);
  cout << path.size() << '\n';
  for(int i=path.size()-1;i>=0;i--)
    cout << path[i] << ' ';
  cout << '\n';

  return 0;
}