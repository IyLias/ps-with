#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>


#define MAXNUM  100001

using namespace std;

vector<pair<int,int>> m_time;

bool cmp(const pair<int,int>& a, const pair<int,int>& b){
   if(a.second == b.second)
      return a.first < b.first;
   else
      return a.second < b.second;
}

int main(){
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);

 int N;
 cin >> N;

 for(int i=0;i<N;i++){

    int s,e;
    cin >> s >> e;

    m_time.push_back({s,e});
 }

 sort(m_time.begin(),m_time.end());
 
 priority_queue<int,vector<int>,greater<int>> pq;
 pq.push(m_time[0].second);

 int ans = 1;
 for(int i=1;i<N;i++){
    while(!pq.empty() && pq.top()<= m_time[i].first)
        pq.pop();
       
    pq.push(m_time[i].second);
    ans = max(ans, (int)pq.size());
 }

 cout << ans << endl;

 return 0;
}
