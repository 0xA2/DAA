#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

typedef struct node {
  bool isBlack;
  bool isNull;
  int value; 
  struct node *left, *right; 
} *Node;

Node mkNode(int v) {
  Node aux = (Node)malloc(sizeof(struct node));
  aux->isNull  = (v==0);
  aux->isBlack = (v>=0);
  aux->value   = abs(v);
  return aux;
}

Node readPreOrder() {
  int v;
  cin >> v;
  Node aux = mkNode(v);
  if (v!=0) {
    aux->left  = readPreOrder();
    aux->right = readPreOrder();
  }
  return aux;
}


int minimum(Node t) {
  if (t->isNull) return INT_MAX;
  int minLeft  = minimum(t->left);
  int minRight = minimum(t->right);
  return min(t->value, min(minLeft, minRight));
}

int maximum(Node t) {
  if (t->isNull) return INT_MIN;
  int maxLeft  = maximum(t->left);
  int maxRight = maximum(t->right);
  return max(t->value, max(maxLeft, maxRight));
}

int size(Node t) {
  if (t->isNull) return 0;
  return 1 + size(t->left) + size(t->right);
}


bool isBST(Node t){
	if( t -> isNull){ return true; }
	if( !(t -> left -> isNull) && (maximum(t -> left)) >= (t -> value) ){ return false; }
	if( !(t -> right -> isNull) && (minimum(t -> right)) <= (t -> value) ){ return false; }
	if(!isBST(t -> left) || !isBST(t -> right)){ return false; }
	return true;
}

bool rootProperty(Node t){
	return t -> isBlack;
}

bool leafProperty(Node t){
	if(t -> isNull){
		return t -> isBlack;
	}
	return leafProperty(t -> left) && leafProperty(t -> right);
}

bool redProperty(Node t){
	if(t -> isNull){ return true; }
	if(!(t -> isBlack) && ( !(t -> left -> isBlack) || !(t -> right -> isBlack) ) ){
		return false;
	}
	return redProperty(t -> left) && redProperty(t -> right);
}

int blackHeight(Node t){
	if(t -> isNull){ return 0;}
	int leftBH = blackHeight(t -> left);
	int rightBH = blackHeight(t -> right);
	if( leftBH == -1 || rightBH == -1 || leftBH != rightBH){ return -1; }
	else{
		if(t -> isBlack)
			return leftBH + 1;
		return leftBH;
	}
}

bool blackProverty(Node t){
	return blackHeight(t) != -1;
}


// ---------------------------------------------------

int main() {
  int i, n;
  Node root;

  cin >> n;
  for (i=0; i<n; i++) {
    root = readPreOrder();
    //printf("Tree with %d nodes (min=%d, max=%d)\n", size(root), minimum(root), maximum(root));
  	if(isBST(root) && rootProperty(root) && leafProperty(root) && redProperty(root) && blackProverty(root)){
  		std::cout << "SIM" << std::endl;
  	}
  	else{
  		std::cout << "NAO" << std::endl;
  	}

  }
  return 0;
}
