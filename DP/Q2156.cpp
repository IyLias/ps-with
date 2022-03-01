#include <stdio.h>
#include <algorithm>

#define MAXNUM  10000

using namespace std;

int glasses[MAXNUM+1];
int dp[MAXNUM+1];

int main(){

int n;
scanf("%d",&n);

for(int i=1;i<=n;i++)
    scanf("%d",&glasses[i]);

dp[1] = glasses[1];
dp[2] = glasses[1] + glasses[2];
for(int i=3;i<=n;i++){ 
    dp[i] = max(dp[i-2]+glasses[i],max(dp[i-3]+glasses[i-1]+glasses[i],dp[i-1]));
}

if(n==1)
  printf("%d\n",dp[1]);
else if(n==2)
  printf("%d\n",dp[2]);
else
  printf("%d\n",dp[n]);

 return 0;
}