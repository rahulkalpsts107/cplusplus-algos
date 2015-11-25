#include<iostream>

class Node
{
	public:
		char data;
		Node * next;	
		Node(char data)
		{
			this->data = data;
			this->next= NULL;	
		}
};

class LinkedList
{
	public:
		int size;
		Node * root;
		LinkedList(int size)
		{
			root = NULL;
			this->size = size;
		}
		addItemToTail(char c)
		{
			Node * temp;
			if(root == NULL)
			{
				temp = getNode();
				temp->next = NULL;
				root = temp;
			}
			
		}
		Node *getNode()
		{
			return new Node(c);
		}
};

int main(int argc,char **argv)
{
	return 0;
}
