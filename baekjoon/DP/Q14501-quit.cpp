#include <stdio.h>
#include <iostream>
#include <algorithm>


using namespace std;

const int MAXNUM=16;

int max_profit[MAXNUM];
int T[MAXNUM], P[MAXNUM];

int main(){
 
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 cout.tie(NULL);

 int N;
 cin >> N;
 
 for(int i=1;i<=N;i++){
    cin >> T[i] >> P[i];

 }

 for(int i=1;i<=N;i++){
    if(i+T[i]-1 <= N)
       max_profit[i] = P[i];
    
    for(int k=1;k<i;k++){
       if(k+T[k]<=i){
	  max_profit[i] = max(max_profit[i], max_profit[k]);

	  if(i+T[i]-1 <= N)
	     max_profit[i] = max(max_profit[i], max_profit[k] + P[i]);
       }
    }

 } 

 int result = 0;
 for(int i=1;i<=N;i++)
    result = max(result, max_profit[i]);
 cout << result << endl;

 return 0;
}
