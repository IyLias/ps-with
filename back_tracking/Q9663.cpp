#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int result;
vector<int> queens; // stores possible queen cols

void search(int N){
   
   // if possible queens are fully stored
   if(queens.size() == N){
       result += 1;
       return;
   }  

   int crow = queens.size();
   
   // find possible col for queen
   for(int j=0;j<N;j++){
        bool pFlag = true;
        for(int k=0;k<queens.size();k++){
            // possible: (crow,j), queens: (k,queens[k])
            // two cases
            // 1) same col
            // 2) row slope = col slope
            
            if(j==queens[k] || (crow-k == abs(j-queens[k]))){
                pFlag = false;
                break;
            }
       }

        if(pFlag == true){
           queens.push_back(j);
           search(N);
           queens.pop_back();
        }

   }

}

int main(){

 int N;
 scanf("%d",&N);
 
 search(N);
 printf("%d\n",result);

 return 0;
}