#include <climits>
#include <iostream>
#include <string>


template<typename T>
struct BSTNode{
	T value;
	int count;
	struct BSTNode* left;
	struct BSTNode* right;

};

template<typename T>
class BinSearchTree{

	private:
		// Atributes
		BSTNode<T>* root;

		// Private auxiliary methods

		void clear(BSTNode<T>* cur);

		int numberNodesAux(BSTNode<T>* node);

		bool containsAux(BSTNode<T>* node, T v);

		BSTNode<T>* insertAux(BSTNode<T>* node, T v);


		int depthAux(BSTNode<T>* node);

		T minvalueAux(BSTNode<T>* node);

		T maxvalueAux(BSTNode<T>* node);


		BSTNode<T>* maxvalueNode(BSTNode<T>* node);


		BSTNode<T>* removeAux(BSTNode<T>* node, T v);

		bool validAux(BSTNode<T>* node, int min, int max);

		int getCountAux(BSTNode<T>* node, T v);

		void incrementCountAux(BSTNode<T>* node, T v);

		void decrementCountAux(BSTNode<T>* node, T v);

		void printPreOrderAux(BSTNode<T>* node);

		void printInOrderAux(BSTNode<T>* node);

		void printPostOrderAux(BSTNode<T>* node);



	public:

		// Constructor
		BinSearchTree();

		// Destructor
		~BinSearchTree();

		// Methods

		bool isEmpty();

		T getroot();

		int numberNodes();

		bool contains(T v);

		void insert(T v);

		void remove(T v);

		int depth();

		T minvalue();

		T maxvalue();

		bool valid();

		int getCount(T v);

		void printPreOrder();

		void printInOrder();

		void printPostOrder();
};



// Private auxiliary methods

template<typename T>
void BinSearchTree<T>::clear(BSTNode<T>* cur){
	if(cur != nullptr){
		if((cur -> left == nullptr) && (cur -> right == nullptr)){
			delete cur;
			cur = nullptr;
		}
		else{
			clear(cur -> left);
			clear(cur -> right);
		}

	}
	return;
}

template<typename T>
int BinSearchTree<T>::numberNodesAux(BSTNode<T>* node){
	if(node == nullptr){
		return 0;
	}
	return 1 + numberNodesAux(node -> left) + numberNodesAux(node -> right);
}

template<typename T>
bool BinSearchTree<T>::containsAux(BSTNode<T>* node, T v){
	if( node == nullptr){
		return false;
	}
	if( v < node -> value){
		return containsAux(node -> left, v);
	}
	if( v > node -> value){
		return containsAux(node -> right, v);
	}
	return true;
}


template<typename T>
BSTNode<T>* BinSearchTree<T>::insertAux(BSTNode<T>* node, T v){
	if(node == nullptr){
		BSTNode<T>* newnode = new BSTNode<T>();
		newnode -> value = v;
		newnode -> count = 1;
		newnode -> left = nullptr;
		newnode -> right = nullptr;
		return newnode;
	}
	if (v == node -> value){ 
    	(node -> count)++; 
        return node; 
    } 
	else if(v < node -> value){
		node -> left = insertAux(node -> left, v);
	}
	else if(v > node -> value){
		node -> right = insertAux(node -> right, v);
	}
	return node;

}

template<typename T>
int BinSearchTree<T>::depthAux(BSTNode<T>* node){
	if(node == nullptr){
		return -1;
	}
	else{
		return 1 + std::max(depthAux(node -> left), depthAux(node -> right));
	}
}

template<typename T>
T BinSearchTree<T>::minvalueAux(BSTNode<T>* node){
	BSTNode<T>* ret = node;
	while(ret -> left != nullptr){
		ret = ret -> left;
	}
	return ret -> value;
}

template<typename T>
T BinSearchTree<T>::maxvalueAux(BSTNode<T>* node){
	BSTNode<T>* ret = node;
	while(ret -> right != nullptr){
		ret = ret -> right;
	}
	return ret -> value;
}


template<typename T>
BSTNode<T>* BinSearchTree<T>::maxvalueNode(BSTNode<T>* node){
	BSTNode<T>* ret = node;
	while(ret -> right != nullptr){
		ret = ret -> right;
	}
	return ret;
}


template<typename T>
BSTNode<T>* BinSearchTree<T>::removeAux(BSTNode<T>* node, T v){
	if(node == nullptr) { return node;}

	if(v < node -> value){
		node -> left = removeAux(node -> left, v);
	}
	else if(v > node -> value){
		node -> right = removeAux(node -> right, v);
	}
	else{
		if (node -> count > 1){
           (node -> count)--; 
           return node; 
        } 
		if(node -> left == nullptr){
			BSTNode<T>* tmp = node -> right;
			free(node);
			return tmp;
		}
		else if(node -> right == nullptr){
			BSTNode<T>* tmp = node -> left;
			free(node);
			return tmp;
		}

		BSTNode<T>* tmp = this -> maxvalueNode(node -> left);
		node -> value = tmp -> value;
		node -> left = removeAux(node -> left, tmp -> value);
	}
	return node;
}

template<typename T>
bool BinSearchTree<T>::validAux(BSTNode<T>* node, int min, int max){
	if(node == nullptr){ return true;}

	if(node -> value < min || node -> value > max){
		return false;
	}

	return validAux(node -> left, min, (node -> value)-1) && validAux(node -> right, (node -> value)+1, max);
}

template<typename T>
void BinSearchTree<T>::printPreOrderAux(BSTNode<T>* node){
	if(node != nullptr){
		std::cout << node -> value << " ";
		printPreOrderAux(node -> left);
		printPreOrderAux(node -> right);
	}
}

template<typename T>
void BinSearchTree<T>::printInOrderAux(BSTNode<T>* node){
	if(node != nullptr){
		printInOrderAux(node -> left);
		std::cout << node -> value << " ";
		printInOrderAux(node -> right);
	}
}

template<typename T>
void BinSearchTree<T>::printPostOrderAux(BSTNode<T>* node){
	if(node != nullptr) {
		printPostOrderAux(node -> left);
		printPostOrderAux(node -> right);
		std::cout << node -> value << " ";
	}
}


// Constructor
template<typename T>
BinSearchTree<T>::BinSearchTree(){
	root = nullptr;
}

// Destructor
template<typename T>
BinSearchTree<T>::~BinSearchTree(){
	clear(root);
}


// Methods
template<typename T>
bool BinSearchTree<T>::isEmpty(){
	return root == nullptr;
}


template<typename T>
T BinSearchTree<T>::getroot(){
	if(root != nullptr)
		return root -> value;
	std::cout << "Empty tree! No root to return" << std::endl;
	return 0;
}

template<typename T>
int BinSearchTree<T>::numberNodes(){
	return numberNodesAux(root);
}

template<typename T>
bool BinSearchTree<T>::contains(T v){
	return containsAux(root,v);
}

template<typename T>
void BinSearchTree<T>::insert(T v){
	root = insertAux(root,v);
}

template<typename T>
void BinSearchTree<T>::remove(T v){
	if(this -> contains(v)){
		root = removeAux(root,v);
	}
}

template<typename T>
int BinSearchTree<T>::depth(){
	int ret = depthAux(root);
	if(ret == -1){
		std::cout << "Empty tree, no depth to calculate" << std::endl;
		return 0;
	}
	return ret;
}

template<typename T>
T BinSearchTree<T>::minvalue(){
	if(root != nullptr){
		return minvalueAux(root);
	}
	return 0;
}

template<typename T>
T BinSearchTree<T>::maxvalue(){
	if(root != nullptr){
		return maxvalueAux(root);
	}
	return 0;
}

template<typename T>
bool BinSearchTree<T>::valid(){
	return validAux(root, INT_MIN, INT_MAX);
}


template<typename T>
void BinSearchTree<T>::printPreOrder(){
	std::cout << "PreOrder: ";
	printPreOrderAux(root);
	std::cout << std::endl;
}

template<typename T>
void BinSearchTree<T>::printInOrder(){
	std::cout << "InOrder: ";
	printInOrderAux(root);
	std::cout << std::endl;
}

template<typename T>
void BinSearchTree<T>::printPostOrder(){
	std::cout << "PostOrder: ";
	printPostOrderAux(root);
	std::cout << std::endl;
}

int main(){
	int a,r,e;
	std::string cenas;
	std::cin >> a;
	std::cin >> r;
	BinSearchTree<int> bst;
	for(int i = 0; i<(a+r); i++){
		std::cin >> cenas;
		if(cenas == "BAK"){
			std::cin >> e;
			bst.insert(e);
		}
		else if(cenas == "MIN"){
			int min = bst.minvalue();
			std::cout << min << std::endl;
			bst.remove(min);
		}
		else if(cenas == "MAX"){
			int max = bst.maxvalue();
			std::cout << max << std::endl;
			bst.remove(max);
		}
	}

	return 0;
}
