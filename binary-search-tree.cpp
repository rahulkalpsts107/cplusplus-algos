#include<iostream>

using namespace std;

class Node
{
public:
	int data;
	Node *left;
	Node *right;
	Node *parent;
	Node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
		this->parent = NULL;
	}
	Node(int data,Node *parent)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
		this->parent = parent;
	}
};

class BinaryTree
{
private:

	void bstInsert(Node *broot,int data)
	{
		if(broot == NULL)
			root = new Node(data);
		else if(data <broot->data)
		{
			if(broot->left == NULL)
				broot->left = new Node(data,broot);
			else
				bstInsert(broot->left,data);
		}
		else if(data >= broot->data)
		{
			if(broot->right == NULL)
				broot->right = new Node(data,broot);
			else
				bstInsert(broot->right,data);
		}
	}

	void inorder(Node *root)
	{
		if(root==NULL)
			return;
		else
		{
			inorder(root->left);
			cout<<root->data<<", ";
			inorder(root->right);
		}
	}

	Node *bstLookUp(Node *root,int data)
	{
		if(root == NULL)
			return NULL;
		else if(root->data == data)
			return root;
		else if(data>root->data)
			return bstLookUp(root->right,data);
		else if(data<root->data)
			return bstLookUp(root->left,data);
		else
			return NULL;
	}

	Node * bstGetSuccessor(Node * node)
	{
		if(node->right != NULL)
			return getMinimum(node->right);
		else
		{
			Node *temp = node;
			Node *child = node;
			Node *parent = node->parent;
			while(parent != NULL && parent->right == child)
			{
				child = parent;
				parent = child->parent;
			}
			return parent;
		}
	}

	Node * bstGetPredecessor(Node *node)
	{
		if(node->left != NULL)
			return getMaximum(node->left);
		else
		{
			Node *temp = node;
			Node *child = node;
			Node *parent = node->parent;
			while(parent != NULL && parent->left == child)
			{
				child = parent;
				parent = child->parent;
			}
			return parent;
		}
	}

	Node * getMinimum(Node *root)
	{
		Node *val = NULL;
		while(root != NULL)
		{
			val = root;
			root=root->left;
		}
		return val;
	}

	Node * getMaximum(Node *root)
	{
		Node *val = NULL;
		while(root != NULL)
		{
			val = root;
			root=root->right;
		}
		return val;
	}

public:
	Node *root;
	int size;
	BinaryTree()
	{
		this->size = 0;
		this->root = NULL;
	}

	void insert(int data)
	{
		bstInsert(root,data);
	}

	void disp()
	{
		inorder(root);
	}

	int find(int data)
	{
		Node *temp = bstLookUp(root,data);
		if(temp == NULL)
			return 0;
		else 
			return !!temp->data;
	}

	void deleteNode(int data)
	{

	}

	int retSuccessor(int data)
	{		
		Node *succ = bstGetSuccessor(bstLookUp(root,data));
		if( succ!= NULL)
			return succ->data;
		else
			return -1;
	}

	int retPredecessor(int data)
	{
		Node *pred = bstGetPredecessor(bstLookUp(root,data));
		if( pred!= NULL)
			return pred->data;
		else
			return -1;	
	}
};

//Binary search tree
int main(int argc, char **argv)
{
	BinaryTree binTree;
	binTree.insert(8);
	binTree.insert(3);
	binTree.insert(10);
	binTree.insert(1);
	binTree.insert(6);
	binTree.insert(14);
	binTree.insert(4);
	binTree.insert(7);
	binTree.insert(13);
	binTree.disp();
	cout<<endl;
	cout<<"found "<<binTree.find(14)<<endl;
	cout<<"succ "<<binTree.retSuccessor(7)<<endl;
	cout<<"pred "<<binTree.retPredecessor(8)<<endl;
	return 0;
}