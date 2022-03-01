#include <stdio.h>
#include <iostream>
#include <utility>
#include <algorithm>
#include <cmath>

#define MAXNUM 128

using namespace std;

int dataMap[MAXNUM+1][MAXNUM+1];
int blueNum=0;
int whiteNum=0;

void searchMap(pair<int,int> topLeft,pair<int,int> bottomRight){

   if(topLeft.first==bottomRight.first && topLeft.second==bottomRight.second){
       if(dataMap[topLeft.first][topLeft.second] == 1)
            blueNum++;
       else
            whiteNum++;
       return;
   }

   int quadSize = floor((bottomRight.first-topLeft.first+1)/2);

   // search current square area
   int checkBit = dataMap[topLeft.first][topLeft.second];
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
    searchMap(make_pair(topLeft.first,topLeft.second),make_pair(topLeft.first+quadSize-1,topLeft.second+quadSize-1));
    searchMap(make_pair(topLeft.first,topLeft.second+quadSize),make_pair(topLeft.first+quadSize-1,bottomRight.second));
    searchMap(make_pair(topLeft.first+quadSize,topLeft.second),make_pair(bottomRight.first,topLeft.second+quadSize-1));
    searchMap(make_pair(topLeft.first+quadSize,topLeft.second+quadSize),make_pair(bottomRight.first,bottomRight.second));
  }else{
      if(checkBit==1)
        blueNum++;
      else
        whiteNum++;
  }
    
}

int main(){

 int N; scanf("%d",&N);

 for(int i=0;i<N;i++) 
    for(int j=0;j<N;j++) 
        scanf("%d",&dataMap[i][j]);
  
 pair<int,int> topLeft = make_pair(0,0); 
 pair<int,int> bottomRight = make_pair(N-1,N-1);

 searchMap(topLeft,bottomRight);

 printf("%d\n%d\n",whiteNum,blueNum);

 return 0; 
}