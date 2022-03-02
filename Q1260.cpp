#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

#define MAXNUM  1000

using namespace std;

int network[MAXNUM+1][MAXNUM+1];
int visited[MAXNUM+1];

void dfs_search(int curNode,int n){

    printf("%d ",curNode);

    for(int i=1;i<=n;i++){
        if(!visited[i] && network[curNode][i] == 1){
            visited[i] = 1;
            dfs_search(i,n);
        }
    }
}

int main(){

  int n,m,v;
  scanf("%d %d %d",&n,&m,&v);

  for(int i=0;i<m;i++){
     int a,b;
     scanf("%d %d",&a,&b);
     network[a][b] = 1;
     network[b][a] = 1;
  }

  visited[v]=1;
  dfs_search(v,n);    
  printf("\n");

  // BFS
  for(int i=1;i<=n;i++)
    visited[i] = 0;
  visited[v] = 1;

  queue<int> bfs;
  bfs.push(v);

  while(!bfs.empty()){
    int curNode = bfs.front();
    printf("%d ",curNode);
    bfs.pop();

    for(int i=1;i<=n;i++)
        if(!visited[i] && network[curNode][i] == 1){
            visited[i] = 1;
            bfs.push(i);
        }
  }
  printf("\n");

  return 0;
}

