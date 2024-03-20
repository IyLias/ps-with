#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

#define MAXNUM  1001

int preorder[MAXNUM];
int inorder[MAXNUM];
int Index[MAXNUM];

using namespace std;


void search_postorder(int preStart,int preEnd,int inStart,int inEnd){
    if(preStart > preEnd || inStart > inEnd)
       return;
    else if(preStart == preEnd || inStart == inEnd){
        printf("%d ",preorder[preStart]);
        return;
    }

    int rootIdx = Index[preorder[preStart]];
    int leftSize = rootIdx - inStart;
    int rightSize = inEnd - rootIdx;

    search_postorder(preStart+1,preStart+leftSize,inStart,inStart+leftSize-1);
    search_postorder(preStart+leftSize+1,preEnd,rootIdx+1,rootIdx+rightSize);

    printf("%d ",preorder[preStart]);
}

int main(){
 
  int T;
  scanf("%d",&T);
  for(int i=0;i<T;i++){
      int n;
      scanf("%d",&n);

      for(int j=0;j<MAXNUM;j++)
         Index[j]=0;   

      for(int j=0;j<n;j++)
         scanf("%d",&preorder[j]); 
      
      for(int j=0;j<n;j++){
        scanf("%d",&inorder[j]); 
        Index[inorder[j]]=j;
      }

      search_postorder(0,n-1,0,n-1);
  }

  return 0;
}