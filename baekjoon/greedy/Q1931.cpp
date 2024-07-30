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

 sort(m_time.begin(),m_time.end(),cmp);
 

 int ans = 0, end_time=0;
 for(int i=0;i<N;i++){
    if(end_time <= m_time[i].first){ 
       ans++;
       end_time = m_time[i].second;
    }
 }

 cout << ans << endl;

 return 0;
}
