#include<iostream>
#include<queue>

using namespace std;

//Check if two trees are identical

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
};

void recurseAndAdd(Node *node1 ,Node *node2)
{
	if(node1 != NULL)
	{
		if(node1->left != NULL)
		{
			node2->right = new Node(node1->left->data);
			recurseAndAdd(node1->left,node2->right);
		}
		if(node1->right != NULL)
		{
			node2->left = new Node(node1->right->data);
			recurseAndAdd(node1->right,node2->left);
		}
	}	
}

void makeMirrorBinaryTree(BinaryTree *tree1 ,BinaryTree *tree2) //Another efficient way - Do inplace and jut swap pointers!
{
	if(tree1->root != NULL)
	{
		tree2->addNode(tree1->root->data);
		recurseAndAdd(tree1->root,tree2->root);
	}
}

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
	tree.addNode(8);
	BinaryTree tree1;
	makeMirrorBinaryTree(&tree ,&tree1);
	tree.inOrder(tree.root);
	cout<<endl;
	cout<<"mirror is ";
	tree1.inOrder(tree1.root);
	cout<<endl;
	return 0;
}