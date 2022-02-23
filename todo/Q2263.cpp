#include <stdio.h>
#include <algorithm>
#include <vector>

#define MAXNUM  100001

using namespace std;

int Index[MAXNUM];
int inorder[MAXNUM];
int preorder[MAXNUM];

void search_preorder(int inStart,int inEnd,int postStart,int postEnd){

    if(inStart>inEnd || postStart > postEnd)
       return;
    
    int rootIndex = Index[postorder[postEnd]];
    int leftSize = 
    int rightSize = ;

    printf("%d ",postorder[postEnd]);

    search_preorder(inStart,rootIndex-1,inStart,rootIndex-1);
    search_preorder(rootIndex+1,postEnd-1, ,postEnd-1);
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
    
  return 0;
}