#include <stdio.h>
#include <iostream>
#include <algorithm>

#define MAXNUM	1001

using namespace std;

int house_price[MAXNUM][3];
int min_price[MAXNUM][3];

int main(){

 int N;
 scanf("%d",&N);

 for(int i=1;i<=N;i++){
    scanf("%d %d %d",&house_price[i][0],&house_price[i][1],&house_price[i][2]);
    if(i == 1){
	min_price[i][0] = house_price[i][0], min_price[i][1] = house_price[i][1];
        min_price[i][2] = house_price[i][2];
    }else{
	   min_price[i][0] = house_price[i][0] + min(min_price[i-1][1],min_price[i-1][2]);
           min_price[i][1] = house_price[i][1] + min(min_price[i-1][0],min_price[i-1][2]);
           min_price[i][2] = house_price[i][2] + min(min_price[i-1][0],min_price[i-1][1]);
    }
 }

 printf("%d\n",min(min(min_price[N][0],min_price[N][1]),min_price[N][2]));

 return 0;
}
