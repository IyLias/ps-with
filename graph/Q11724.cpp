#include <stdio.h>
#include <iostream>
#include <algorithm>

#define MAXNUM  1000

using namespace std;

int graph[MAXNUM+1][MAXNUM+1];
bool visited[MAXNUM+1];

void search(int idx,int N){

    visited[idx] = true;
    for(int i=0;i<N;i++){
        if(!visited[i] && graph[idx][i] == 1)
            search(i,N);
    }

}


int main(){

 int N,M;
 scanf("%d %d",&N,&M);

 for(int i=0;i<M;i++){
     int u,v;
     scanf("%d %d",&u,&v);
     graph[u-1][v-1] = 1;
     graph[v-1][u-1] = 1;
 }
 
 int connected=0;
 for(int i=0;i<N;i++){
     if(!visited[i]){
         search(i,N);
         connected++;
     }
 }

 printf("%d\n",connected);

 return 0;
}