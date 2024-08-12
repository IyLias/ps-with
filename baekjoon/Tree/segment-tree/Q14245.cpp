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

long long query(vector<long long> &tree, vector<long long> &lazy, int node, int start, int end, int idx) {
    update_lazy(tree, lazy, node, start, end);
    if (idx > end || idx < start) {
        return 0;
    }
    if (start==end && start==idx) {
        return tree[node];
    }
    long long lxor = query(tree, lazy, node*2, start, (start+end)/2, idx);
    long long rxor = query(tree, lazy, node*2+1, (start+end)/2+1, end, idx);
    
     
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
            int ss,b;
            long long c;
            cin >> ss >> b >> c;
            update_range(tree,lazy, 1, 0, n-1, ss,b, c);
        } else if (what == 2) {
            int idx;
            cin >> idx;
            cout << query(tree,lazy, 1, 0, n-1, idx) << '\n';
        }
    }
    return 0;
}
