#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

long long init(vector<long long> &arr,vector<long long> &tree,int node,int start,int end){ 
    if(start==end) 
        return (tree[node] = arr[start]); 
    else 
        return (tree[node] = init(arr,tree,2*node,start,(start+end)/2) + init(arr,tree,2*node+1,(start+end)/2+1,end) ); 
}

long long sum(vector<long long> &arr,vector<long long> &tree,int node,int start,int end,int left,int right){ 
    if(left > end || right < start) 
        return 0;
    else if(left<=start && end<=right)
        return tree[node];
    else 
        return sum(arr,tree,2*node,start,(start+end)/2,left,right) + sum(arr,tree,2*node+1,(start+end)/2+1,end,left,right);
}

void update(vector<long long> &arr,vector<long long> &tree,int node,int index,int start,int end,int k){
    if(index == start && index == end){
        tree[node] = k;
        return tree[node];
    }
    else if(start<= index && index <= end){
        return tree[node] = update(arr,tree,2*node,index,start,(int)((start+end)/2),k) + update(arr,tree,2*node+1,index,(int)((start+end)/2)+1,end,k);
    }else
        return tree[node];
}

int main(){

  int n; scanf("%d",&n);

  vector<long long> arr(n);

  int h = (int)ceil(log2(n)); 
  int tree_size = (1 << (h+1));
  vector<long long> segment_tree(tree_size);

  for(int i=0;i<n;i++) 
    scanf("%lld",&arr[i]);

  return 0; 
}