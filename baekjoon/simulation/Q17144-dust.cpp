#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <utility>

#define MAXNUM  50

using namespace std;

pair<int,int> room[MAXNUM][MAXNUM];
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

int main()
{   
    int R,C,T;
    cin >> R >> C >> T;
    
    bool top_flag = false;
    int cleaner_top = 0, cleaner_bottom = 0;
    for(int i=0;i<R;i++)
       for(int j=0;j<C;j++){
          cin >> room[i][j].first;   
          
          if (room[i][j] == -1){
             if(top_flag == false){
                top_flag = true;
                cleaner_top = i;
             } else{
                 cleaner_bottom = i;
             }
          
          }
       }
    
    
    // For T sec
    for (int i=0;i<T;i++){
        
        // Diffusion
        for(int r=0;r<R;r++)
	   for(int c=0;c<C;c++)
	      if(room[r][c] != -1)
	         room[r][c].second = floor(room[r][c].first/5);	      
	   
	for(int r=0;r<R;r++)
	   for(int c=0;c<C;c++){
              
	      // for 4 directions 
     	      for(int d=0;d<4;d++){
		int mr = r + dir[d][0];
		int mc = c + dir[d][1];

		if(!((mr==cleaner_top && mc==0) || (mr==cleaner_bottom && mc==0) || mr<0 || mr>=R || mc<0 || mc>=C)){
		   room[mr][mc].first += room[r][c].second;
		}
	      }
	   }
	
        // cleaner 
        
	// circulate counter-clockwise
	int r_bot = room[cleaner_top][C-1].first;
	for(int c=C-1;c>1;c--)
	   room[cleaner_top][c].first = room[cleaner_top][c-1].first;
	
	int r_top = room[0][C-1].first;
	for(int r=cleaner_top-1;r>0;r--){
  	    int temp1 = room[r][C-1].first;
	    int temp2 = 

	    if(r == cleaner_top-1)
	       room[r][C-1].first = r_bot;
	    else
	       room[r][C-1].first = temp;

	    room[r][C-1].first = room[r+1][C-1].first;
        
	}

	for(int c=0;c<C;c++)
	   room[0][c].first = room[0][c+1].first;

	
	// circulate clockwise



        
    }
    
    // calculate how much dust left in the room
    int total_dust = 0;
    for(int i=0;i<R;i++)
       for(int j=0;j<C;j++)
           total_dust += room[i][j];
    
    cout << total_dust << endl;
    
    return 0;
}
