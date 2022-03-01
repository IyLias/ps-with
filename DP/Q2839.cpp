#include <stdio.h>
#include <algorithm>

#define MAXNUM  5000
#define INF     112345678

using namespace std;

int main(){

  int N;
  scanf("%d",&N);
 
  int dp[MAXNUM+1]; 
  dp[1] = INF,dp[2] = INF;
  dp[3] = 1,dp[4] = INF, dp[5] = 1;

  for(int i=6;i<=N;i++){
      if(dp[i-3]==INF && dp[i-5]==INF)
        dp[i] = INF;
      else
        dp[i] = min(dp[i-3]+1,dp[i-5]+1);
  }

  printf("%d\n",dp[N]!=INF?dp[N]:-1);
 
  return 0;
}