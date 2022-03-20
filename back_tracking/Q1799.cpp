#include <stdio.h>
#include <iostream>
#include <algorithm>

#define MAXNUM  20

using namespace std;

int board[MAXNUM+1][MAXNUM+1];
int leftArr[MAXNUM];
int rightArr[MAXNUM];

int N;
int maxResult[2];

void search(int r,int c,int count,int color){

  if(c>=N){
    r++;
    if(c%2)
      c=0;
    else c=1;  
  }

  if(r>=N){
      maxResult[color] = max(maxResult[color],count);
      return;
  }

  if(board[r][c] && !leftArr[c-r+N-1] && !rightArr[r+c]){
      leftArr[c-r+N-1] = rightArr[r+c] = 1;
      search(r,c+2,count+1,color);
      leftArr[c-r+N-1] = rightArr[r+c] = 0;
  }

  search(r,c+2,count,color);
}

int main(){

 ios_base :: sync_with_stdio(false);
 cin.tie(NULL);
 cout.tie(NULL);

 cin >> N;

 for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
        cin >> board[i][j]; 

 search(0,0,0,0);
 search(0,1,0,1);
 
 cout << maxResult[0] + maxResult[1] << '\n';

 return 0;
}