#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <utility>

#define INF     1123456789

using namespace std;

pair<long long,long long> init(vector<long long> &arr,vector<pair<long long, long long>> &tree,int node,int start,int end){ 
    if(start==end){
        tree[node].first = arr[start]; tree[node].second = arr[start]; 
        return tree[node]; 
    }
    else{ 
        pair<long long,long long> leftPart = init(arr,tree,2*node,start,(int)((start+end)/2));
        pair<long long,long long> rightPart = init(arr,tree,2*node+1,(int)((start+end)/2)+1,end);
        tree[node].first = min(leftPart.first, rightPart.first); 
        tree[node].second = max(leftPart.second, rightPart.second); 
        
        return tree[node];
    }
}

pair<long long, long long> get_result(vector<long long> &arr,vector<pair<long long,long long>> &tree,int node,int start,int end,int left,int right){ 
    
    if(left > end || right < start) 
        return make_pair(INF,-INF);
    else if(left<=start && end<=right)
        return tree[node];
    else{
        pair<long long,long long> leftPart = get_result(arr,tree,2*node,start,(int)((start+end)/2),left,right);
        pair<long long,long long> rightPart = get_result(arr,tree,2*node+1,(int)((start+end)/2)+1,end,left,right);
       
        return make_pair(min(leftPart.first,rightPart.first),max(leftPart.second,rightPart.second));
    }

}


int main(){

  int n,m; 
  scanf("%d %d",&n,&m);

  vector<long long> arr(n);

  int h = (int)ceil(log2(n)); 
  int tree_size = (1 << (h+1));
  vector<pair<long long,long long>> segment_tree(tree_size+1);

  for(int i=0;i<n;i++) 
    scanf("%lld",&arr[i]);

  init(arr,segment_tree,1,0,n-1);

  for(int i=0;i<m;i++){
      long long a,b;
      scanf("%lld %lld",&a,&b);
      pair<long long, long long> result = get_result(arr,segment_tree,1,0,n-1,a-1,b-1);  
      printf("%lld %lld\n",result.first,result.second);
  }

  return 0; 
}