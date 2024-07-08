#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <iostream>

using namespace std;

// top, left, down, right
int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};


class BabyShark{

 public:
   BabyShark(int N, int imap[20][20]){
      this->size = 2;
      this->N = N;

      this->map = new int*[N];
      for (int i=0;i<N;i++)
	   this->map[i] = new int[N];

      for(int i=0;i<N;i++)
	  for(int j=0;j<N;j++){
	      this->map[i][j] = imap[i][j];
		
	      if(imap[i][j] == 9){
		this->sr = i;
		this->sc = j;
		
		this->map[i][j] = 0;
	      }

	  }

      this->eaten = 0;

   }

   int get_size(){
	return this->size;
   }
   
   void print_map(){
	
   	for(int i=0;i<N;i++){
 	   for(int j=0;j<N;j++)
	      printf("%d ", this->map[i][j]);
 	   printf("\n");  
	}

   } 


   bool check_no_fish(){

      for(int i=0;i<this->N;i++)
	  for(int j=0;j<this->N;j++)
	     if(this->map[i][j] != 0)
		return false;
      
      return true;
   }
   
   int count_fish(){

      int num=0;
      for(int i=0;i<this->N;i++)
	 for(int j=0;j<this->N;j++)
	    if(this->map[i][j] != 0)
		 num++;

      return num;
   }

   // find fish to eat right after
   int find_next_target(){

       // baby shark searches the map finding fish with priority rules 
       int dist=0;

       queue<pair<int,int>> q;
       q.push({sr,sc});
       
       priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
       int visited[20][20]={0,};

       visited[sr][sc] = 1;
       while(!q.empty()){
 	  
	   int r = q.front().first;
	   int c = q.front().second;
		
	   q.pop();
	   
	   
	   if(visited[r][c] == dist)
		break;

	   for(int i=0;i<4;i++){
	      int mr = r + dir[i][0];
	      int mc = c + dir[i][1];
	      if(!(mr<N && mr>=0 && mc < N && mc>=0))
		  continue;

              if(visited[mr][mc])
		  continue;

	      if(this->map[mr][mc]==0 || this->map[mr][mc] == this->size){
		  q.push({mr,mc});
		  visited[mr][mc] = visited[r][c]+1;
	      }
 	      else if(this->map[mr][mc] < this->size){
	 	  if(!dist)
		    this->eaten++;

		  visited[mr][mc] = visited[r][c]+1;
		  dist = visited[mr][mc];
		  pq.push({mr,mc});

	      }
	       
	   }
       }


       if(pq.empty())
	  return 0;

       sr = pq.top().first;
       sc = pq.top().second;
       //cout << "sr: " << sr << "," << "sc: " << sc << ", eaten: " << eaten << endl;

       this->map[sr][sc] = 0;
       if(this->eaten == this->size){
	 this->size++;
	 this->eaten=0;
       }

       return visited[sr][sc]-1;
   }



   int behave(){
      // Here's the main function that baby shark behaves following the rules
      int result=0;

      while(true){
          
         int time = find_next_target();
	 //cout << "passed time: " << time << endl;
	 result += time;
         if(time == 0)
	    break;

      }
  
      return result;
   } 


 private:

   int N;
   int size;	
   int sr;
   int sc;

   int eaten;

   int** map;

};

int main(){

 int N;
 scanf("%d",&N); 

 int map[20][20];
 for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
       scanf("%d", &map[i][j]);

 BabyShark bshark(N, map);
 //bshark.behave(); 
 //bshark.print_map();

 printf("%d\n",bshark.behave());

 return 0;
}
