#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>


using namespace std;

class Node{

 public:
  
   char value;
   Node* left;
   Node* right;


   Node(char value, Node* left = NULL, Node* right= NULL){

      this->value = value;
      this->left = left;
      this->right = right;

   }

   void add_leftChild(Node* left){
	this->left = left;
   }

   Node* get_leftChild(){
        return this->left;
   }

   void add_rightChild(Node* right){
	this->right = right;
   }

   Node* get_rightChild(){
	return this->right;
   }

};



class Tree{

  public:
   
    Node* root;

    Tree(char value=0, Node* left= NULL, Node* right= NULL){
            root = new Node(value,left,right);
    }

    void treeAddChild(char p, char c1, char c2){

	   Node* targetNode = getChild(this->root,p);
	   
	   if(c1 != '.')
	     targetNode->add_leftChild(new Node(c1,NULL,NULL));
	   
	   if(c2 != '.')
	     targetNode->add_rightChild(new Node(c2,NULL,NULL));
    }

    Node* getChild(Node* node, char value){

        if(node == NULL)
	  return NULL;

	if(node->value == value)
	  return node;
	
	Node* result1 = getChild(node->left,value);
	if(result1 != NULL)
	  return result1;
	Node* result2 = getChild(node->right,value);
        return result2;
    }


    // return depth of tree
    int get_tree_depth(){

        if(this->root == NULL)
	  return 0;

	queue<Node*> node_queue;
	node_queue.push(this->root);

	int depth = -1;

	while(!(node_queue.empty())){

          depth+=1;
	  int temp_size = node_queue.size();
	  for(int i=0;i<temp_size;i++){
	      //Node* cur_root = node_queue.pop();
	     // if(cur_root->leftChild != NULL)
	//	  node_queue.push(cur_root->leftChild);
//
//	      if(cur_root->rightChild != NULL)
//		  node_queue.push(cur_root->rightChild);
          }

	}


        return depth;
    }


    void preorder_traversal(Node* node){

	    if(node == NULL)
	      return;

	    cout << node->value;

	    preorder_traversal(node->left);
	    preorder_traversal(node->right);

    }


    void inorder_traversal(Node* node){

         if(node == NULL)
            return;

	 inorder_traversal(node->left);
	 cout << node->value;
	 inorder_traversal(node->right);

    }


    void postorder_traversal(Node* node){


	 if(node == NULL)
            return;

	 postorder_traversal(node->left);
	 postorder_traversal(node->right);
	 cout << node->value;
    }



};



int main(){

 int N;
 scanf("%d",&N);
 Tree* sampleTree = new Tree('A',NULL,NULL);

 for(int i=0;i<N;i++){

   char p,c1,c2;
   //scanf("%c %c %c",&p,&c1,&c2);
   cin >> p >> c1 >> c2;

   sampleTree->treeAddChild(p,c1,c2);
 }

 sampleTree->preorder_traversal(sampleTree->root);
 printf("\n");
 sampleTree->inorder_traversal(sampleTree->root);
 printf("\n");
 sampleTree->postorder_traversal(sampleTree->root);
 printf("\n");

 return 0;
}
