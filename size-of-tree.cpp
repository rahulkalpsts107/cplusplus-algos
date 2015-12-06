#include<iostream>
#include<vector>
//Calculate size(nodes) of a tree
//size = size of left(subtree) + right(subtree) + 1

using namespace std;

class Node
{
public:
	int data;
	Node *left;
	Node *right;
	Node(int data, Node *left, Node *right)
	{
		this->left = left;
		this->right = right;
	}
	Node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

//Recursive way
int retSizeOfTree(Node *root)
{
	if(root == NULL)
		return 0;
	else
		return retSizeOfTree(root->left) + 1 + retSizeOfTree(root->right);
}

//Non recursive
int retSizeOfTreeNonRecur(Node *root)
{
	int size = 0;
	if(root == NULL) return size;
	vector<Node *> frontier;
	frontier.push_back(root);
	while(!frontier.empty())
	{
		Node *iter = frontier.back();
		frontier.pop_back();
		size++;
		if(iter!=NULL)
		{
			if(iter->left != NULL)
				frontier.push_back(iter->left);
			if(iter->right != NULL)
				frontier.push_back(iter->right);
		}
	}
	return size;
}

int main(int argc,char **argv)
{
	Node * root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	//cout<<"size of tree is "<<retSizeOfTree(root)<<endl;
	cout<<"size of tree is "<<retSizeOfTreeNonRecur(root)<<endl;	
	return 0;
}