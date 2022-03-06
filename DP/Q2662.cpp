#include <stdio.h>
#include <algorithm>

using namespace std;

int profit[301][21]; 
int maxdp[301][21];
int path[21];

int main(){

    int N,M; 
    scanf("%d %d",&N,&M);

    for(int i=1;i<=N;i++){ 
        int price; 
        scanf("%d",&price);

        for(int j=1;j<=M;j++)
            scanf("%d",&profit[i][j]); 
    }

    int temp_result=0; 
    for(int i=1;i<=N;i++){ 
        for(int j=1;j<=M;j++){ 
            for(int k=0;k<=i;k++){ 
                temp_result = maxdp[i-k][j-1] + profit[k][j]; 
                maxdp[i][j] = max(maxdp[i][j],temp_result); 
            }
        }
    }

    printf("%d\n",maxdp[N][M]);

    int price = N;
    for(int j=M;j>=1;j--)
        for(int k=0;k<=price;k++)
            if(maxdp[price][j] == maxdp[price-k][j-1] + profit[k][j]){
                path[j] = k;
                price -= k;
                break;
            }

    for(int i=1;i<=M;i++)
        printf("%d ",path[i]);
    printf("\n");

    return 0; 
}