#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

bool cmp(const pair<int, int>& a, const pair<int,int>& b){

  if(a.second != b.second)
    return a.second < b.second;
  else if(a.second == b.second)
    return a.first < b.first;  

}


int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  vector<pair<int,int>> locations;
  priority_queue<int, vector<int>, greater<int>> pq;
  int d;
  
  for(int i=0;i<n;i++){
      
    int h,o;
    scanf("%d %d",&h,&o);
    
    locations.push_back({min(h,o), max(h,o)});  
  }
  
  cin >> d;
  
  sort(locations.begin(), locations.end(),cmp);
  
  int max_result = 0;
  for(int i=0;i<n;i++){
    int pL = locations[i].first;
    int pR = locations[i].second;

    if(pR-pL <= d) pq.push(pL);
    else continue;
    
    while(!pq.empty()){
 	int cL = pq.top();
	if (pR-cL <= d) break;
	else
	   pq.pop();
    }  
    
      
    max_result = max(max_result, (int)pq.size()); 
  }
  
  
  cout << max_result << endl;
  
  return 0;
}
