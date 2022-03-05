#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#define DIV     1000000007

using namespace std;

long long init(vector<long long> &arr,vector<long long> &tree,int node,int start,int end){ 
    if(start==end) 
        return (tree[node] = arr[start]); 
    else 
        return (tree[node] = init(arr,tree,2*node,start,(int)((start+end)/2)) * init(arr,tree,2*node+1,(int)((start+end)/2)+1,end) % DIV); 
}

long long product(vector<long long> &arr,vector<long long> &tree,int node,int start,int end,int left,int right){ 
    if(left > end || right < start) 
        return 1;
    else if(left<=start && end<=right)
        return tree[node];
    else 
        return (product(arr,tree,2*node,start,(int)((start+end)/2),left,right) * product(arr,tree,2*node+1,(int)((start+end)/2)+1,end,left,right))%DIV;
}

long long update(vector<long long> &arr,vector<long long> &tree,int node,int index,int start,int end,long long k){
    if(index == start && index == end){
        tree[node] = k;
        return tree[node];
    }
    else if(start<= index && index <= end){
        return tree[node] = (update(arr,tree,2*node,index,start,(int)((start+end)/2),k) * update(arr,tree,2*node+1,index,(int)((start+end)/2)+1,end,k))%DIV;
    }else
        return tree[node];
}

int main(){

  int n,m,k; 
  scanf("%d %d %d",&n,&m,&k);

  vector<long long> arr(n);

  int h = (int)ceil(log2(n)); 
  int tree_size = (1 << (h+1));
  vector<long long> segment_tree(tree_size+1);

  for(int i=0;i<n;i++) 
    scanf("%lld",&arr[i]);

  init(arr,segment_tree,1,0,n-1);

  for(int i=0;i<m+k;i++){
      long long a,b,c;
      scanf("%lld %lld %lld",&a,&b,&c);

      if(a == 1){
        arr[b-1] = c;
        update(arr,segment_tree,1,b-1,0,n-1,c);
      }else{
        printf("%lld\n",product(arr,segment_tree,1,0,n-1,b-1,c-1));
      }

  }

  return 0; 
}