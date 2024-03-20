#include <stdio.h>
#include <iostream>
#include <algorithm>

#define MAXNUM	1001
#define INF	10000001

using namespace std;

int house_price[MAXNUM][3];
int min_price[MAXNUM][3];

int main(){

 int N;
 scanf("%d",&N);

 for(int i=1;i<=N;i++){
    scanf("%d %d %d",&house_price[i][0],&house_price[i][1],&house_price[i][2]);
 }

 int ans = INF;
 for(int k=0;k<3;k++){
	 
     for(int i=1;i<=N;i++){
     	if(i == 1){ 
	     for(int j=0;j<3;j++)
		if(j == k) 
		  min_price[i][k] = house_price[i][k];
	        else
		  min_price[i][j] = INF;
        }else{
	     min_price[i][0] = house_price[i][0] + min(min_price[i-1][1],min_price[i-1][2]);
	     min_price[i][1] = house_price[i][1] + min(min_price[i-1][0],min_price[i-1][2]);
	     min_price[i][2] = house_price[i][2] + min(min_price[i-1][0],min_price[i-1][1]);
        }

     }

     for(int j=0;j<3;j++){
	if(j == k) continue;

	ans = min(ans,min_price[N][j]);
     }
 }

 printf("%d\n",ans);

 return 0;
}
