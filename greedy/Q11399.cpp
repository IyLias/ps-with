#include <stdio.h>
#include <algorithm>

#define MAXNUM  1000

using namespace std;


int main(){

  int N;
  scanf("%d",&N);

  int time[MAXNUM+1];
  for(int i=0;i<N;i++)
    scanf("%d",&time[i]);
  
  sort(time,time+N);

  int totalTime=0;
  for(int i=0;i<N;i++){
    int p=0;
    for(int j=0;j<=i;j++){
        p+=time[j];
    }
    totalTime+=p;
  }

  printf("%d\n",totalTime);

  return 0;
}