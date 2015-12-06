#include<iostream>
#include<queue>
#include<cmath>
// all types of dfs traversals on a binary tree

using namespace std;

class Node
{
public:
	int data;
	Node *left;
	Node *right;
	Node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

class BinaryTree
{
public:
	Node *root;
	int size;
	BinaryTree()
	{
		this->size = 0;
		this->root = NULL;
	}

	void addNode(int data)
	{
		if(size == 0)
		{
			 size++;
			 root = new Node(data);
		}
		else
		{
			queue<Node *> nodes;
			nodes.push(root);
			while(!nodes.empty())
			{
				Node *temp = nodes.front();
				nodes.pop();
				if(temp->left == NULL)
				{
					temp->left = new Node(data);
					return;
				}
				else if(temp->right == NULL)
				{
					temp->right = new Node(data);
					return;
				}
				else
				{
					nodes.push(temp->left);
					nodes.push(temp->right);
				}
			}
		}
	}

	int retHeight(Node *node)
	{
		if(node == NULL)
			return 0;
		else return max(retHeight(node->left),retHeight(node->right)) +1;
	}
};

int main(int argc,char **argv)
{

	BinaryTree tree;
	tree.addNode(1);
	tree.addNode(2);
	tree.addNode(3);
	tree.addNode(4);
	tree.addNode(5);
	tree.addNode(6);
	tree.addNode(7);
	cout<<"height is "<<tree.retHeight(tree.root)<<endl;
	return 0;
}