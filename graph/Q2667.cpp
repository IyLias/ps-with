#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <utility>

#define MAXNUM 25

using namespace std;

char map[MAXNUM+1][MAXNUM+1]; 
bool visited[MAXNUM+1][MAXNUM+1];
int totalResult; 
vector<int> danji;

int search(int r,int c,int *house){

    visited[r][c] = true;
    *house += 1;

    if(r-1>=0 && map[r-1][c] == '1' && visited[r-1][c] == false)
        search(r-1,c,house);

    if(c-1>=0 && map[r][c-1] == '1' && visited[r][c-1] == false)
        search(r,c-1,house);
    
    if(r+1>=0 && map[r+1][c] == '1' && visited[r+1][c] == false)
        search(r+1,c,house);

    if(c+1>=0 && map[r][c+1] == '1' && visited[r][c+1] == false)
        search(r,c+1,house);

    return *house;
}

int main(){

  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int N; 
  cin >> N;

  for(int i=0;i<N;i++) 
    cin >> map[i];

  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
        if(map[i][j] == '1' && visited[i][j] == false){
            totalResult+=1;
            int house = 0;
            int totalhouse = search(i,j,&house);
            danji.push_back(totalhouse);
        }

  sort(danji.begin(),danji.end());

  cout << totalResult << '\n'; 
  for(int i=0;i<danji.size();i++) 
     cout << danji[i] << '\n'; 
  
  return 0; 
}