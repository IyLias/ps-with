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
          
          if (room[i][j].first == -1){
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
	      if(room[r][c].first != -1)
	         room[r][c].second = int(floor(room[r][c].first/5));	      
	   
	for(int r=0;r<R;r++)
	   for(int c=0;c<C;c++){
              if((r==cleaner_top && c==0) || (r==cleaner_bottom && c==0))
		  continue;

	      // for 4 directions 
     	      for(int d=0;d<4;d++){
		int mr = r + dir[d][0];
		int mc = c + dir[d][1];

		if(!((mr==cleaner_top && mc==0) || (mr==cleaner_bottom && mc==0) || mr<0 || mr>=R || mc<0 || mc>=C)){
		   room[mr][mc].first += room[r][c].second;
		   room[r][c].first -= room[r][c].second;
		}
	      }
	   }
	
	for(int p=0;p<R;p++){
	   for(int q=0;q<C;q++)
	     cout << room[p][q].first << " ";
           cout << endl;
        }

        // cleaner 
        
	// circulate counter-clockwise
	int r_bot = room[cleaner_top][C-1].first;
	int r_top = room[0][C-1].first;
	int l_top = room[0][0].first;

	for(int c=C-1;c>1;c--)
	   room[cleaner_top][c].first = room[cleaner_top][c-1].first;
	room[cleaner_top][1].first = 0;
	for(int r=0;r<cleaner_top;r++)
	   room[r][C-1].first = room[r+1][C-1].first;		
	for(int c=0;c<C-1;c++)
	   room[0][c].first = room[0][c+1].first;
	for(int r=cleaner_top-1;r>0;r--)
	   room[r][0].first = room[r-1][0].first;

	room[1][0].first = l_top;
	room[0][C-2].first = r_top;
	room[cleaner_top-1][C-1].first = r_bot;
	
	// circulate clockwise
	r_top = room[cleaner_bottom][C-1].first;
	r_bot = room[R-1][C-1].first;
	int l_bot = room[R-1][0].first;

	for(int c=C-1;c>1;c--)
	   room[cleaner_bottom][c].first = room[cleaner_bottom][c-1].first;
	room[cleaner_bottom][1].first = 0;
	for(int r=R-1;r>cleaner_bottom;r--)
	   room[r][C-1].first = room[r-1][C-1].first;		
	for(int c=0;c<C-1;c++)
	   room[R-1][c].first = room[R-1][c+1].first;
	for(int r=cleaner_bottom+1;r<R-1;r++)
	   room[r][0].first = room[r+1][0].first;

	room[cleaner_bottom+1][C-1].first = r_top;
	room[R-1][C-2].first = r_bot;
	room[R-2][0].first = l_bot;
        
    }
    
    // calculate how much dust left in the room
    int total_dust = 0;
    for(int i=0;i<R;i++)
       for(int j=0;j<C;j++)
	   if(room[i][j].first != -1)
              total_dust += room[i][j].first;
    
    cout << total_dust << endl;
   
    for(int i=0;i<R;i++){
	for(int j=0;j<C;j++)
	   cout << room[i][j].first << " ";
        cout << endl;
    }


    return 0;
}
