#include <stdio.h>
#include <iostream>
#include <utility>
#include <algorithm>
#include <cmath>

#define MAXNUM 2187
#define MINUS_ONE   -1
#define ZERO        0
#define ONE         1

using namespace std;

int dataMap[MAXNUM+1][MAXNUM+1];

int minus_one=0;
int zero=0;
int one=0;

void searchMap(pair<int,int> topLeft,pair<int,int> bottomRight){

   if(topLeft.first==bottomRight.first && topLeft.second==bottomRight.second){
       if(dataMap[topLeft.first][topLeft.second] == MINUS_ONE)
            minus_one++;
       else if(dataMap[topLeft.first][topLeft.second] == ZERO)
            zero++;
       else
            one++;

       return;
   }

   int divSize = floor((bottomRight.first-topLeft.first+1)/3);

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
    searchMap(make_pair(topLeft.first,topLeft.second),make_pair(topLeft.first+divSize-1,topLeft.second+divSize-1));
    searchMap(make_pair(topLeft.first,topLeft.second+divSize),make_pair(topLeft.first+divSize-1,topLeft.second+2*divSize-1));
    searchMap(make_pair(topLeft.first,topLeft.second+2*divSize),make_pair(topLeft.first+divSize-1,topLeft.second+3*divSize-1));
    
    searchMap(make_pair(topLeft.first+divSize,topLeft.second),make_pair(topLeft.first+2*divSize-1,topLeft.second+divSize-1));
    searchMap(make_pair(topLeft.first+divSize,topLeft.second+divSize),make_pair(topLeft.first+2*divSize-1,topLeft.second+2*divSize-1));
    searchMap(make_pair(topLeft.first+divSize,topLeft.second+2*divSize),make_pair(topLeft.first+2*divSize-1,topLeft.second+3*divSize-1));
    
    searchMap(make_pair(topLeft.first+2*divSize,topLeft.second),make_pair(topLeft.first+3*divSize-1,topLeft.second+divSize-1));
    searchMap(make_pair(topLeft.first+2*divSize,topLeft.second+divSize),make_pair(topLeft.first+3*divSize-1,topLeft.second+2*divSize-1));
    searchMap(make_pair(topLeft.first+2*divSize,topLeft.second+2*divSize),make_pair(topLeft.first+3*divSize-1,topLeft.second+3*divSize-1));  
  }else{
      if(checkBit==MINUS_ONE)
        minus_one++;
      else if(checkBit == ZERO)
        zero++;
      else
        one++;
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

 printf("%d\n%d\n%d\n",minus_one,zero,one);

 return 0; 
}