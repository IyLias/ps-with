#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
void init(vector<long long> &a, vector<long long> &tree, int node, int start, int end) {
    if (start == end) {
        tree[node] = a[start];
    } else {
        init(a, tree, node*2, start, (start+end)/2);
        init(a, tree, node*2+1, (start+end)/2+1, end);
        tree[node] = tree[node*2] ^ tree[node*2+1];
    }
}


void update_lazy(vector<long long>& tree, vector<long long>& lazy, int node, int start,int end){

    if(lazy[node] != 0){
        tree[node] ^= lazy[node] * ((end-start+1)%2);
        if(start != end){
           lazy[2*node] ^= lazy[node];
           lazy[2*node+1] ^= lazy[node];
        }
        lazy[node] = 0;
    }

}


void update_range(vector<long long> &tree, vector<long long> &lazy, int node, int start, int end, int left, int right, long long val) {
    update_lazy(tree,lazy,node,start,end);
    if (left > end || right < start) {
        return;
    }

    if (left<=start && end<=right){ 
        tree[node] ^= val * ((end-start+1)%2);
        if(start != end){
           lazy[2*node] ^= val;
           lazy[2*node+1] ^= val;
        }
        return;
    }

    update_range(tree,lazy,node*2, start, (start+end)/2, left,right, val);
    update_range(tree,lazy,node*2+1, (start+end)/2+1, end, left,right, val);
    tree[node] = tree[node*2] ^ tree[node*2+1];
}

long long query(vector<long long> &tree, vector<long long> &lazy, int node, int start, int end, int left, int right) {
    update_lazy(tree, lazy, node, start, end);
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    long long lxor = query(tree, lazy, node*2, start, (start+end)/2, left, right);
    long long rxor = query(tree, lazy, node*2+1, (start+end)/2+1, end, left, right);
    
     
    return lxor ^ rxor;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m;
    cin >> n;
    vector<long long> a(n);
    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h+1));
    vector<long long> tree(tree_size);
    vector<long long> lazy(tree_size);
   
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    init(a, tree, 1, 0, n-1);
    cin >> m;
    while (m--) {
        int what;
        cin >> what;
        if (what == 1) {
            int b,c;
            long long k;
            cin >> b >> c >> k;
            update_range(tree,lazy, 1, 0, n-1, b,c, k);
        } else if (what == 2) {
            int left, right;
            cin >> left >> right;
            cout << query(tree,lazy, 1, 0, n-1, left, right) << '\n';
        }
    }
    return 0;
}
