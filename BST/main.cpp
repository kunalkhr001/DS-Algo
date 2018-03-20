#include <iostream>
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

BinaryTreeNode<int>* sortedArrayToBST(int arr[], int start, int end)
{
    if (start > end)
      return NULL;

    int mid = (start + end)/2;
    BinaryTreeNode<int>* root =new BinaryTreeNode<int> (arr[mid]);


    root->left =  sortedArrayToBST(arr, start, mid-1);

    root->right = sortedArrayToBST(arr, mid+1, end);

    return root;
}


BinaryTreeNode<int>* constructTree(int *input, int n) {
  	return sortedArrayToBST(input,0,n-1);
}

class BST
{
    BinaryTreeNode<int>* root;
   public:
    BST()
    {
        root=NULL;
    }


	void printTree()
    {
        if(root==NULL)
            return;
     	    queue<BinaryTreeNode<int>*> pendingNodes;
  		pendingNodes.push(root);
 	 while(pendingNodes.size()!=0)
  	{
    BinaryTreeNode<int>* currentNode = pendingNodes.front();
		pendingNodes.pop();
		cout << currentNode->data << ":";
		if(currentNode->left != NULL){
			cout << "L:"<<currentNode->left->data << ",";
			pendingNodes.push(currentNode->left);

		}
		if(currentNode->right != NULL){
			cout << "R:"<<currentNode->right->data;
			pendingNodes.push(currentNode->right);
		}
		cout << endl;
  	}
    }


    void insert(int el)
    {
        root=insert(root,el);
    }

    void deleteData(int el)
    {
        root=deleteData(root,el);
    }

    bool hasData(int el)
    {
       return hasData(root,el);
    }


    private:
    bool hasData(BinaryTreeNode<int>* root,int el)
    {
        if(root==NULL)
            return false;
        if(root->data==el)
            return true;
        else if(root->data>el)
            return hasData(root->left,el);
        else
            return hasData(root->right,el);
    }

    BinaryTreeNode<int>* insert(BinaryTreeNode<int>* root,int el)
    {
		if(root==NULL)
        {
          BinaryTreeNode<int>* newNode=new BinaryTreeNode<int> (el);
          root=newNode;

        }
      else if(el>root->data)
      {
      	root->right=insert(root->right,el);

      }
      else
        root->left=insert(root->left,el);



      return root;
    }

    BinaryTreeNode<int>* deleteData(BinaryTreeNode<int>* root,int el)
    {
        if(root==NULL)
          return root;
      if(root->data==el)
      {
        if(root->left==NULL && root->right==NULL)
        {
          delete root;
          return NULL;
        }
        else if(root->left!=NULL)
        {
          BinaryTreeNode<int>* temp=root;
          root=root->left;
          delete temp;
        }
        else if(root->right!=NULL)
        {
          BinaryTreeNode<int>* temp=root;
          root=root->right;
          delete temp;
        }

        else
        {
          BinaryTreeNode<int>* successor=root->right;
          while(successor->left!=NULL)
          {
            successor=successor->left;
          }
          root->data=successor->data;
          root->right=deleteData(root->right,successor->data);
          return root;
        }

      }
      else if(root->data<el)
      {
        root->right=deleteData(root->right,el);
      }
      else
      {
        root->left=deleteData(root->left,el);
      }
      return root;
    }

};

int main()
{
      BST *tree = new BST();
    int choice, input;
    while(true){
        cin>>choice;
        switch(choice){
            case 1:
                cin >> input;
                tree->insert(input);
                break;
            case 2:
                cin >> input;
                tree->deleteData(input);
                break;
            case 3:
                cin >> input;
                if(tree->hasData(input)) {
                    cout << "true" << endl;
                }
                else {
                    cout << "false" << endl;
                }
                break;
            default:
                tree->printTree();
                return 0;
                break;
        }
    }
    return 0;
}
