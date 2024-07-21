#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

#define MAXNUM 1000000

using namespace std;

const int INF = 1e9+1;

int main(){
 vector<pair<int,int>> lines;

 int N;
 cin >> N;
 for(int i=0;i<N;i++){
    int a,b;
    scanf("%d %d",&a,&b);
    lines.push_back({a,b});
 }

 sort(lines.begin(),lines.end());

 int total_length = 0, l = -INF, r = -INF;

 for(int i=0;i<N;i++){
 
   if(lines[i].first < r){
      r = max(r, lines[i].second);
      
   }else{
      total_length += (r-l);
      l = lines[i].first;
      r = lines[i].second;
   }   
 }
 
 total_length += (r-l);
 printf("%d\n",total_length);

 return 0;
}
