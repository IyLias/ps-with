#include <stdio.h>
#include <algorithm>
#include <vector>

#define MAXNUM  100

using namespace std;

int network[MAXNUM+1][MAXNUM+1];
int visited[MAXNUM+1];
int virus=0;

void search(int curNode,int n){

    for(int i=1;i<=n;i++){
        if(!visited[i] && network[curNode][i] == 1){
            visited[i] = 1;
            virus++;
            search(i,n);
        }
    }
}

int main(){

  int n,m;
  scanf("%d %d",&n,&m);

  for(int i=0;i<m;i++){
     int a,b;
     scanf("%d %d",&a,&b);
     network[a][b] = 1;
     network[b][a] = 1;
  }

  visited[1] = 1;

  search(1,n);    
  printf("%d\n",virus);
  
  return 0;
}

