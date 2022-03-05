#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <utility>

#define INF     1123456789

using namespace std;

long long init(vector<long long> &arr,vector<long long> &tree,int node,int start,int end){ 
    if(start==end)
        return tree[node] = arr[start]; 
    else
        return tree[node] = min(init(arr,tree,2*node,start,(int)((start+end)/2)), init(arr,tree,2*node+1,(int)((start+end)/2)+1,end));
}

long long get_result(vector<long long> &arr,vector<long long> &tree,int node,int start,int end,int left,int right){ 
    
    if(left > end || right < start) 
        return INF;
    else if(left<=start && end<=right)
        return tree[node];
    else
        return min(get_result(arr,tree,2*node,start,(int)((start+end)/2),left,right),get_result(arr,tree,2*node+1,(int)((start+end)/2)+1,end,left,right));
}


int main(){

  int n,m; 
  scanf("%d %d",&n,&m);

  vector<long long> arr(n);

  int h = (int)ceil(log2(n)); 
  int tree_size = (1 << (h+1));
  vector<long long> segment_tree(tree_size+1);

  for(int i=0;i<n;i++) 
    scanf("%lld",&arr[i]);

  init(arr,segment_tree,1,0,n-1);

  for(int i=0;i<m;i++){
      long long a,b;
      scanf("%lld %lld",&a,&b);
      long long result = get_result(arr,segment_tree,1,0,n-1,a-1,b-1);  
      printf("%lld\n",result);
  }

  return 0; 
}