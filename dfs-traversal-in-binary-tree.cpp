#include<iostream>
#include<queue>
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
					size++;
					return;
				}
				else if(temp->right == NULL)
				{
					temp->right = new Node(data);
					size++;
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

	void inOrder(Node *node)
	{
		if(node == NULL)
			return;
		else
		{
			inOrder(node->left);
			cout<<node->data<<", ";
			inOrder(node->right);
		}
	}

	void preOrder(Node *node)
	{
		if(node == NULL)
			return;
		else
		{
			cout<<node->data<<", ";
			preOrder(node->left);
			preOrder(node->right);
		}
	}

	void postOrder(Node *node)
	{
		if(node == NULL)
			return;
		else
		{
			postOrder(node->left);
			postOrder(node->right);
			cout<<node->data<<", ";
		}
	}
};

int main(int argc, char **argv)
{
	BinaryTree tree;
	tree.addNode(1);
	tree.addNode(2);
	tree.addNode(3);
	tree.addNode(4);
	tree.addNode(5);
	tree.addNode(6);
	tree.addNode(7);
	cout<<"inorder ";
	tree.inOrder(tree.root);
	cout<<endl;
	cout<<"preorder ";
	tree.preOrder(tree.root);
	cout<<endl;
	cout<<"postorder ";
	tree.postOrder(tree.root);
	cout<<endl;
	cout<<endl;
	return 0;	
}