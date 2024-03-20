#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>

#define MAXNUM	20

using namespace std;

int totalNum=0;
vector<int> A;
vector<int> selected;

void search(int N,int S,int sum,int cur){

  if(cur >= N){
     if(sum == S)
       totalNum+=1;
     return;
  } 


  search(N,S,sum+A[cur],cur+1);
  
  search(N,S,sum,cur+1);
   
}

int main(){

 int N,S;
 scanf("%d %d",&N,&S);

 for(int i=0;i<N;i++){
    int num;
    scanf("%d",&num);
    A.push_back(num);
 }

 search(N,S,0,0);

 printf("%d\n",S==0?totalNum-1:totalNum);

 return 0;
}
