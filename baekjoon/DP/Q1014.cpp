#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dir[4][2] = {{0,-1},{-1,-1},{-1,1},{0,1}};
int max_ans = 0;

vector<string> room(10);

void search(int r,int c,int M,int N){
    
    
    
    
    
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int T;
  cin >> T;
  
  for(int i=0;i<T;i++){
      
    int M,N;
    cin >> M >> N;
       
    for(int m=0;m<M;m++)
       cin >> room[m];
      
    max_ans = 0;
    search(room,);
    
    cout << max_ans << endl;
  }

  return 0;
}
