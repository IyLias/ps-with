#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

#define INF 2123456789

using namespace std;

int main(){

  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int N,num;
  cin >> N;

  vector<int> arr;
  for(int i=0;i<N;i++){
     cin >> num;
     arr.push_back(num);
  }

  int max_length=0;  
  vector<long long> max_arr(N+1,INF);
  max_arr[0] = -INF;

  vector<int> index(N+1);
    
  for(int i=0;i<N;i++){
      int j = lower_bound(max_arr.begin(),max_arr.end(),arr[i])-max_arr.begin();
      if(arr[i] >= max_arr[j]){
         max_arr[j] = arr[i];
         index[i] = j; 
      }
      else if(max_arr[j-1]<arr[i] && max_arr[j]>arr[i]){
         max_arr[j] = arr[i];
         index[i] = j;
      }
  }
    
  for(int i=0;i<N+1;i++)
     if(max_arr[i] < INF)
         max_length = i;
  cout << max_length << '\n';

  vector<int> result;
  int find_idx = max_length;
  for(int i=N-1;i>=0;i--){    
     if(find_idx == index[i]){
        result.push_back(arr[i]);
        find_idx--;
     }
  }

  for(int i=result.size()-1;i>=0;i--)
    cout << result[i] << ' ';
  cout << '\n';

  return 0;
}