#include<iostream>
#include<queue>
using namespace std;

template<typename T>
class BinaryTreeNode{
	public:

	T data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;

	BinaryTreeNode(T data){
		this->data = data;
		left = NULL;
		right = NULL;
	}

};


BinaryTreeNode<int>* lcaBST(BinaryTreeNode<int>* root,int n1,int n2)
{
    if(root==NULL)
        return NULL;
    if(root->data>n1 && root->data>n2)
        return lca(root->left,n1,n2);
    if(root->data<n1 && root->data<n2)
        return lca(root->right,n1,n2);
       return root;
}

BinaryTreeNode<int>*  takeInput(){
	int rootData;
	cout << "Enter root " << endl;
	cin >> rootData;
	if(rootData == -1){
		return NULL;
	}
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	// Left subtree
	root->left = takeInput();
	root->right = takeInput();
	return root;
}

void print(BinaryTreeNode<int>* root){
	if(root == NULL){
		return;
	}

	cout << root->data << ": " ;
	if(root->left != NULL)
		cout <<"L: " << root->left->data << ", " ;
	if(root->right != NULL)
		cout << "R: " << root->right->data;
	cout << endl;
	print(root->left);
	print(root->right);
}

BinaryTreeNode<int>* takeInputLevelWise(){
	int rootData;
	cout << "Enter root " << endl;
	cin >> rootData;

	if(rootData == -1){
		return NULL;
	}
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);

	while(!pendingNodes.empty()){
		BinaryTreeNode<int>* currentNode = pendingNodes.front();
		pendingNodes.pop();
		int leftData;
		int rightData;
		cout << "Enter left child of " << currentNode->data << endl;
		cin >> leftData;
		if(leftData != -1){
			BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(leftData);
		currentNode->left = leftChild;
		pendingNodes.push(leftChild);
		}
		cout << "Enter right child of " << currentNode->data << endl;
		cin >> rightData;
		if(rightData != -1){
			BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(rightData);
		currentNode->right = rightChild;
		pendingNodes.push(rightChild);
		}
	}
	return root;

}

int maxNode(BinaryTreeNode<int>* root)
{
    if(root==NULL)
        return 0;
    BinaryTreeNode<int>* maxl=root->left;
    BinaryTreeNode<int>* maxr=root->right;
    if(maxl->data>maxr->data)
        return maxl->data;
    else
        return maxr->data;
    int maxLeft=maxNode(maxl);
    int maxRight=maxNode(maxr);
    return max(maxLeft,maxRight);
}

void printLevelWise(BinaryTreeNode<int>* root){
	if(root == NULL){
		return;
	}
	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while(! pendingNodes.empty()){
		BinaryTreeNode<int>* currentNode = pendingNodes.front();
		pendingNodes.pop();
		cout << currentNode->data << ": ";
		if(currentNode->left != NULL){
			cout << currentNode->left->data << ", ";
			pendingNodes.push(currentNode->left);
		}
		if(currentNode->right != NULL){
			cout << currentNode->right->data << ", ";
			pendingNodes.push(currentNode->right);
		}
		cout << endl;
	}
}

int countNodes(BinaryTreeNode<int>* root){

	if(root == NULL){
		return 0;
	}
	int leftCount = countNodes(root->left);
	int rightCount = countNodes(root->right);
	return leftCount + rightCount + 1 ;
}

bool findNode(BinaryTreeNode<int>* root, int x){
	if(root == NULL){
			return false;
	}
	// if root matches -> true
	if(root->data == x){
		return true;
	}
	bool leftAns = findNode(root->left, x);
	if(leftAns){
		return true;
	}
	bool rightAns = findNode(root->right, x);
	return rightAns;
	//return leftAns || rightAns;

}

void preOrder(BinaryTreeNode<int>* root){
	if(root == NULL){
		return;
	}

	cout << root->data << " " ;
	preOrder(root->left);
	preOrder(root->right);
}

int height(BinaryTreeNode<int>* root){

	return root == NULL ? 0 : 1 + max(height(root->left), height(root->right));

}

// O(n * h)
int diameter(BinaryTreeNode<int>* root){
	if(root == NULL){
		return 0;
	}

	int lH = height(root->left);
	int rH = height(root->right);
	int op1 = lH + rH + 1;
	int leftD = diameter(root->left);
	int rightD = diameter(root->right);
	return max(max(leftD, rightD), op1);
}

class DiameterRT{
	public:

	int height;
	int diameter;

};

DiameterRT diameterBetter(BinaryTreeNode<int>* root){
	if(root == NULL){
		DiameterRT ans;
		ans.height = 0;
		ans.diameter = 0;
		return ans;
	}

	DiameterRT leftAns = diameterBetter(root->left);
	DiameterRT rightAns = diameterBetter(root->right);
	int op1 = leftAns.height + rightAns.height + 1;
	int op2 = leftAns.diameter;
	int op3 = rightAns.diameter;

	DiameterRT ans;
	ans.diameter = max(max(op1,op2),op3);
	ans.height = max(leftAns.height, rightAns.height) + 1;
	return ans;

}

int diameter2(BinaryTreeNode<int>* root){
	DiameterRT ans = diameterBetter(root);
	return ans.diameter;
}

/*
BinaryTreeNode<int>* buildTree(int* pre, int* in, int preS, int preE, int inS, int inE){
		if(inS > inE){
			return NULL;
		}

		int rootData = pre[preS];
		BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);



		root->left = buildTree(pre, in, preS + 1, , inS);
		root->right = buildTree();
		return root;
}
*/

//10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1
int main(){
//max(max(a,b), c)

		BinaryTreeNode<int>* root = takeInputLevelWise();
		printLevelWise(root);
		cout<<maxNode(root);
		//cout << "Count " << countNodes(root) << endl;
		//	BinaryTreeNode<int> root(10);
//	cout << root.data << endl;
/*	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(20);
	cout << root->data << endl;
	BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(30);
	BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(40);
	root->left = node1;
	root->right = node2;
*/

}

