#include <stdio.h>
#include <algorithm>
#include <vector>

#define MAXNUM  11
#define BISHOP  2

using namespace std;

int chess_board[MAXNUM][MAXNUM];
int bishop_board[MAXNUM][MAXNUM];

int bishop_dir[4][2] = {{-1,-1},{-1,1},{1,-1},{1,1}};

void search(int cur_r,int cur_c,int N){

   if(cur_r >= N || cur_c >= N)
      return;

   for(int i=cur_r;i<N;i++)
      for(int j=cur_c;j<N;j++){

          if(bishop_board[i][j] != BISHOP){
              bishop_board[i][j] = BISHOP;
              
              search()

          }

      }

}


int main(){
 
  int N;
  scanf("%d",&N);

  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++){
        scanf("%d",&chess_board[i][j]);
        bishop_board[i][j] = chess_board[i][j];
    }
   
   search(0,0,N);
  
   return 0;
}