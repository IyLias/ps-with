#include <stdio.h>
#include <algorithm>
#include <string.h>

#define MAX 21
#define INF 1123456789

using namespace std;

int n; 
int work[MAX][MAX]; 
int dp[(1<<21)-1];

int search(int bmask,int curIdx){

  if(curIdx == n)
    return 0;

  if(dp[bmask] != 0)
    return dp[bmask];

  dp[bmask] = INF;
  for(int i=0;i<n;i++)
    if(!(bmask & (1<<i))){
        dp[bmask] = min(dp[bmask],search(bmask | (1<<i),curIdx+1)+work[curIdx][i]);
        printf("dp value: %d\n",dp[bmask]);
    }

  return dp[bmask];
}

int main(){

  scanf("%d",&n); 
  for(int i=0;i<n;i++) 
    for(int j=0;j<n;j++) 
      scanf("%d",&work[i][j]);

  printf("%d\n",search(0,0));

  return 0; 
}

