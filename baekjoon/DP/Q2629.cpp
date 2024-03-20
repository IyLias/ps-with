#include <stdio.h>
#include <algorithm>
#include <cstdlib>

#define MAXWEIGHT   40000

using namespace std;

int c,n;
int weight[31];
int marbles[8];

int dp[31][MAXWEIGHT+1];
bool pFlag = false;

void search(int mWeight,int lWeight,int rWeight,int curIdx){

    if(pFlag == false && mWeight+lWeight == rWeight){
        printf("Y ");
        pFlag = true;
        return;
    }

    if(curIdx == c)
        return;

    search(mWeight,lWeight,rWeight,curIdx+1);
    search(mWeight,lWeight+weight[curIdx+1],rWeight,curIdx+1);
    search(mWeight,lWeight,rWeight+weight[curIdx+1],curIdx+1);
}

int main(){

 scanf("%d",&c);
 for(int i=1;i<=c;i++)
    scanf("%d",&weight[i]);

 scanf("%d",&n);
 for(int i=1;i<=n;i++)
    scanf("%d",&marbles[i]);

 for(int i=1;i<=c;i++){
    dp[i][weight[i]] = 1;
    for(int j=1;j<=MAXWEIGHT;j++){
        if(dp[i-1][j] == 1){
            dp[i][j] = 1;
            if(weight[i]+j<=MAXWEIGHT)
                dp[i][weight[i]+j] = 1;
            dp[i][abs(j-weight[i])] = 1;
        }
    }
 }
 
  for(int i=1;i<=n;i++)
    printf("%c ",dp[c][marbles[i]] == 1?'Y':'N');

  printf("\n");
  for(int i=0;i<=c;i++){
    for(int j=0;j<=10;j++)
        printf("%d ",dp[i][j]);
    printf("\n");
  }

  return 0;
}