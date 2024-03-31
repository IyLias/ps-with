#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
const int MAXNUM = 100;

typedef vector<int> vi;
typedef vector<vector<int>> vii;

struct SCC{

int n,nxt_dfsn;
vii edges, scc;
vi dfsn, fin, sccn;
stack<int> S;

SCC(int n): n(n),edges(n), dfsn(n, -1), fin(n), sccn(n) {};
void add_edge(int u, int v) {edges[u].push_back(v);}

int dfs(int i) {  
      int ret = dfsn[i] = nxt_dfsn++;  
      S.push(i);  
  
      for (int to: edges[i]) {  
         if (fin[to]) continue;  
         if (dfsn[to] != -1) ret = min(ret, dfsn[to]);  
         else ret = min(ret, dfs(to));  
      }  
  
      if (ret == dfsn[i]) {  
         scc.emplace_back();  
         while (1) {  
            int t = S.top();  
            S.pop();  
            scc.back().push_back(t);  
            fin[t] = 1, sccn[t] = scc.size() - 1;  
            if (t == i) break;  
         }  
      }  
  
      return ret;  
   }  

 void build() {  
      for (int i = 0; i < n; i++) if (dfsn[i] == -1) dfs(i);  
   }  
 
 bool two_sat(){
    for (int i=0; i<n; i+= 2)
        if(sccn[i] == sccn[i+1])
            return false;
    
    return true;
 }   
    
};


inline int inv(int i) { return i ^ 1; }  

void solve() {  
   int n, m;  
   cin >> n >> m;  
  
   SCC scc(n * 2);  
  
   for (int i = 0; i < m; i++) {  
      int a, b;  
      cin >> a >> b;  
      int is_not = a < 0;  
      a = (abs(a) - 1) * 2 + 1;  
      if (is_not) a = inv(a);  
  
      is_not = b < 0;  
      b = (abs(b) - 1) * 2 + 1;  
      if (is_not) b = inv(b);  
  
      scc.add_edge(inv(a), b);  
      scc.add_edge(inv(b), a);  
   }  
  
   scc.build();  
  
   if (scc.two_sat()) cout << 1;  
   else cout << 0;  
}

int main(){
 
 solve();
 
 return 0;
}