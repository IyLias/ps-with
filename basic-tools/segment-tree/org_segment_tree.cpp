#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// init segment tree based on array a
void init(vector<long long>& a, vector<long long>& tree, int node, int start, int end){
  
    if(start == end){
	tree[node] = a[start];
    }
    else{
	long long lvalue = init(a, tree, 2*node, start, (start+end)/2);
	long long rvalue = init(a, tree, 2*node+1, (start+end)/2+1,end);
	tree[node] = lvalue + rvalue;
    }

}



void update(vector<long long>& a, vector<long long>& tree, int idx, int val){

   int diff = val - a[idx];
   a[idx] = val;
   
   update(tree,1,0,n-1,idx,diff);
}


// update value for all corresponding one in segment tree
void update(vector<long long>& tree, int node, int start, int end, int idx, int diff){

  if(start>idx || idx>end) return;

  tree[node] = tree[node] + diff;
  if(start!=end){
    update(tree,2*node, start,(start+end)/2, idx,diff);
    update(tree,2*node+1,(start+end)/2+1,end,idx,diff);
  }

}

// query for calculating value for interval [left,right]
long long query(vector<long long>& tree, int node, int start, int end, int left, int right){

   if(end < left || right < start)
      return 0;
   else{
      if(left<=start && end<=right)
	  return tree[node];

      return query(tree,2*node, start,(start+end)/2,left,right) 
	     + query(tree, 2*node+1, (start+end)/2+1,end,left,right);
   }

}


int main(){

 int n,m,k;
 cin >> n >> m >> k;

 vector<long long> a(n);
 int h = (int)ceil(log2(n));
 int tree_size = (1 << (h+1));
 vector<long long> tree(tree_size);



 return 0;
}
