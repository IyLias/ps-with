#include <stdio.h>
#include <iostream>
#include <utility>
#include <algorithm>
#include <cmath>

#define MAXNUM 64

using namespace std;

char dataMap[MAXNUM+1][MAXNUM+1];

void quadTree(pair<int,int> topLeft,pair<int,int> bottomRight){

   if(topLeft.first==bottomRight.first && topLeft.second==bottomRight.second){
       printf("%c",dataMap[topLeft.first][topLeft.second]);
       return;
   }

   int quadSize = floor((bottomRight.first-topLeft.first+1)/2);

   // search current square area
   char checkBit = dataMap[topLeft.first][topLeft.second];
   bool diffFlag = false;

   for(int i=topLeft.first;i<=bottomRight.first;i++){
     for(int j=topLeft.second;j<=bottomRight.second;j++)
        if(checkBit != dataMap[i][j]){
            diffFlag = true;
            break;
        }

    if(diffFlag == true)
        break;
  }

  if(diffFlag == true){
    printf("(");
    quadTree(make_pair(topLeft.first,topLeft.second),make_pair(topLeft.first+quadSize-1,topLeft.second+quadSize-1));
    quadTree(make_pair(topLeft.first,topLeft.second+quadSize),make_pair(topLeft.first+quadSize-1,bottomRight.second));
    quadTree(make_pair(topLeft.first+quadSize,topLeft.second),make_pair(bottomRight.first,topLeft.second+quadSize-1));
    quadTree(make_pair(topLeft.first+quadSize,topLeft.second+quadSize),make_pair(bottomRight.first,bottomRight.second));
    printf(")");
  }else
    printf("%c",checkBit);

}

int main(){

 int N; scanf("%d",&N);

 for(int i=0;i<N;i++) 
    scanf("%s",dataMap[i]);
  
 pair<int,int> topLeft = make_pair(0,0); 
 pair<int,int> bottomRight = make_pair(N-1,N-1);

 quadTree(topLeft,bottomRight);

 return 0; 
}