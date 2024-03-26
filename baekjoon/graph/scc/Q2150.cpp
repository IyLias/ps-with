#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
const int MAXNUM = 10000;

typedef vector<int> vi;
typedef vector<vector<int>> vii;

int V,E,cnt, dfsn[MAXNUM], SN, sn[MAXNUM];
vi adj[MAXNUM];
bool finished[MAXNUM];
stack<int> S;
vii SCC;

int dfs(int curr){

 dfsn[curr] = ++cnt;
 S.push(curr);

 int result = dfsn[curr];
 for(int next: adj[curr]){
    if(dfsn[next] == 0) result = min(result, dfs(next));
    else if (!finished[next]) result = min(result, dfsn[next]);
 }

 if(result == dfsn[curr]){
    vi currSCC;
    while(1){
	 int t = S.top();
	 S.pop();

	 currSCC.push_back(t);
	 finished[t] = true;
	 sn[t] = SN;
	 if(t == curr) break;
    }

    sort(currSCC.begin(), currSCC.end());
    SCC.push_back(currSCC);
    SN++;

  } 

 return result;
}

int main(){
 
 scanf("%d %d", &V, &E);
 for(int i=0;i<E;i++){
    int A,B;
    scanf("%d %d", &A,&B);
    adj[A-1].push_back(B-1);
 }
 
 for(int i=0;i<V;i++)
    if(dfsn[i] == 0) dfs(i);

 printf("%d\n",SN);

 sort(SCC.begin(), SCC.end(),
      [](const vi& a, const vi& b){
       	 return a.front() < b.front();
	 }
     );
 for(auto& currSCC: SCC){
    for(int curr: currSCC)
       printf("%d ", curr+1);
    printf("-1\n");
  }
 return 0;
}
