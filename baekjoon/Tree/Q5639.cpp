#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

#define MAXNUM  10001

using namespace std;

vector<int> preorder;

void search_postorder(int start,int end){

    if(start > end)
      return;
    else if(start == end){
        printf("%d\n",preorder[start]);
        return;
    }
      
    int curRoot = preorder[start];
    int lessCount = 0;
    int biggerCount = 0;
    int curEnd = end;
    bool first_detect_flag = false;

    // classify for 3 cases
    // 1) curRoot value is bigger than all other nodes
    // 2) curRoot value is less than all other nodes
    // 3) else
    for(int i=start+1;i<=end;i++){
        if(curRoot > preorder[i])
            biggerCount += 1;
        else{
            if(first_detect_flag == false){
                first_detect_flag = true;
                curEnd = i;
            }
            
            lessCount += 1;
        }
    }

    if(lessCount == 0 || biggerCount == 0)
        search_postorder(start+1,end);
    else{
       search_postorder(start+1,curEnd-1);
       search_postorder(curEnd,end);
    }

    printf("%d\n",curRoot);
}


int main(){
 
  int val;
  while(scanf("%d",&val) != EOF){
      preorder.push_back(val);
  }

  search_postorder(0,preorder.size()-1);

  return 0;
}