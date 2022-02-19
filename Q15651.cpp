#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;

void search(int M,int N){

  if(arr.size() == M){
    for(int j=0;j<arr.size();j++)
 	printf("%d ",arr[j]);
    printf("\n");
    return;
  }

  for(int i=1;i<=N;i++){
     arr.push_back(i);	
     search(M,N);
     arr.pop_back();
  }

}

int main(){

int N,M;
scanf("%d %d",&N,&M);

search(M,N);

return 0;
}
