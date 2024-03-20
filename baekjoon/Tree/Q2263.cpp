#include <stdio.h>
#include <algorithm>
#include <vector>

#define MAXNUM  100001

using namespace std;

int Index[MAXNUM];
int inorder[MAXNUM];
int postorder[MAXNUM];

void search_preorder(int inStart,int inEnd,int postStart,int postEnd){

    if(inStart>inEnd || postStart > postEnd)
       return;
    
    int rootIndex = Index[postorder[postEnd]];
    int leftSize = rootIndex - inStart;
    int rightSize = inEnd - rootIndex;

    printf("%d ",postorder[postEnd]);

    search_preorder(inStart,rootIndex-1,postStart,postStart+leftSize-1);
    search_preorder(rootIndex+1,rootIndex+rightSize,postStart+leftSize,postStart+leftSize+rightSize-1);
} 


int main(){

  int n;
  scanf("%d",&n);

  for(int i=0;i<n;i++){
      scanf("%d",&inorder[i]);
      Index[inorder[i]] = i;
  }

  for(int i=0;i<n;i++)
      scanf("%d",&postorder[i]);
  
  search_preorder(0,n-1,0,n-1); 
  printf("\n");

  return 0;
}