#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>

#define MAX_NUM -1

using namespace std;

vector<long long> aa;
vector<long long> tree;

// init segment tree based on array a
void init(int node, int start, int end){

    if(start == end){
        tree[node] = aa[start];
    }
    else{
        init(2*node, start, (start+end)/2);
        init(2*node+1, (start+end)/2+1,end);
        tree[node] = min(tree[2*node], tree[2*node+1]);
    }

}



// update value for all corresponding one in segment tree
void update(int node, int start, int end, int index, long long val) {
    
   if(index<start || end<index) return;
 
   if(start==end){
       aa[index] = val;
       tree[node] = val;
       return;
   }
 
   update(2*node, start, (start+end)/2, index, val);
   update(2*node+1, (start+end)/2+1,end,index,val);
   tree[node] = min(tree[2*node], tree[2*node+1]);        
}


// query for calculating value for interval [left,right]
long long query(int node, int start, int end, int left, int right){

   if(end < left || right < start)
      return -1;
   
   if(left<=start && end<=right)
      return tree[node];

   long long lans = query(2*node, start,(start+end)/2,left,right);
   long long rans = query(2*node+1, (start+end)/2+1,end,left,right);
   if(lans == -1)
      return rans;
   else if(rans == -1)
      return lans;
   else
      return min(lans,rans);

}

int main(){
 ios_base::sync_with_stdio(false);
 cin.tie(NULL); cout.tie(NULL);

 int n,m;
 cin >> n;

 int h = (int)ceil(log2(n));
 int tree_size = (1 << (h+1));
 aa.resize(n);
 tree.resize(tree_size);

 for(int i=0;i<n;i++)
    cin >> aa[i];

 init(1,0,n-1);

 cin >> m;
 while (m--) {
        int what;
        cin >> what;
        if (what == 1) {
            int index, val;
            cin >> index >> val;
            update(1, 0, n-1, index-1, val);
        } else if (what == 2) {
            int left, right;
            cin >> left >> right;
            cout << query(1, 0, n-1, left-1, right-1) << '\n';
        }
 }

 return 0;
}
