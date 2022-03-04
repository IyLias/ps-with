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



}

long long update(vector<long long> &arr,vector<long long> &tree,int node,int index,int start,int end){



}

int main(){
 
 int n;
 scanf("%d",&n);

 vector<long long> arr(n);

 int h = (int)ceil(log2(n));
 int tree_size = (1 << (h+1));
 vector<long long> segment_tree(tree_size);

 for(int i=0;i<n;i++)
   scanf("%lld",&arr[i]);

 
 

 
 return 0;
}