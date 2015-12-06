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
};

int checkIfSame(Node *t1 ,Node *t2)
{
	//cout<<"times "<<t1->data<<" "<<t2->data<<endl;
	if(t1 == NULL && t2 == NULL)
		return 1;
	if(t1 != NULL && t2 != NULL)
	{
		if(t1->data == t2->data)
			return 1 & checkIfSame(t1->left,t2->left) & checkIfSame(t1->right,t2->right);
	}
	return 0;
}

int main(int argc ,char **argv)
{
	BinaryTree tree;
	tree.addNode(1);
	tree.addNode(2);
	tree.addNode(3);
	tree.addNode(4);
	tree.addNode(5);
	tree.addNode(6);
	tree.addNode(7);
	tree.addNode(9);
	BinaryTree tree1;
	tree1.addNode(1);
	tree1.addNode(2);
	tree1.addNode(3);
	tree1.addNode(4);
	tree1.addNode(5);
	tree1.addNode(6);
	tree1.addNode(7);
	tree1.addNode(10);
	cout<<checkIfSame(tree.root ,tree1.root)<<endl;
	return 0;
}