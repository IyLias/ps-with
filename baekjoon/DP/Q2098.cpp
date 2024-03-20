#include <stdio.h>
#include <iostream>
#include <algorithm>

#define INF 1123456789
#define MAXNUM 16

using namespace std;

int N; 
int cost[MAXNUM+1][MAXNUM+1]; 
int dp[MAXNUM+1][(1<<MAXNUM)-1]; 

int search(int bmask,int curIdx){

    // if visited all 
    if(bmask == (1<<N)-1){
        if(cost[curIdx][0] == 0) return INF;
        else 
            return cost[curIdx][0];
    }

    if(dp[curIdx][bmask] != 0)
        return dp[curIdx][bmask];

    dp[curIdx][bmask] = INF;
    for(int i=0;i<N;i++){
        if(cost[curIdx][i] == 0) continue;
        if(!(bmask & (1<<i))){
            dp[curIdx][bmask] = min(dp[curIdx][bmask],search(bmask | (1<<i),i)+cost[curIdx][i]);
        }
    }
        
    return dp[curIdx][bmask];
}

int main(){

  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  cin >> N;

  for(int i=0;i<N;i++) 
    for(int j=0;j<N;j++) 
        cin >> cost[i][j];

  int result = search(1,0); 
  cout << result << '\n';

  return 0; 
}

