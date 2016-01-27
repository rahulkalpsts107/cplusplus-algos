//Reverse linked list in place

#include <iostream>

using namespace std;

class Node
{
public:
	Node(int data)
	{
		this->data =data;
		next = NULL;
	}
	int data;
	Node *next;
};

class LinkedList
{
public:
	Node *head;
	int size;
	LinkedList()
	{
		head =NULL;
		size =0;
	}

	void insert(int data)
	{
		if(size ==0)
			head = new Node(data);
		else
		{
			Node *temp = new Node(data);
			temp->next = head;
			head = temp;
		}
		incSize();
	}

	void incSize()
	{
		size++;
	}

	void decSize()
	{
		size--;
	}

	void disp()
	{
		Node *temp = head;
		while(temp != NULL)
		{
			cout<<temp->data<<" ,";
			temp = temp->next;
		}
		cout<<endl;
	}

	void revLinkedList()
	{
		Node *curr = head;
		Node *next ;
		Node *prev = NULL;
		while(curr)
		{
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		head = prev;
	}
};

int main()
{
	LinkedList ll;
	ll.insert(1);
	//ll.insert(2);
	//ll.insert(3);
	//ll.insert(4);
	//ll.insert(5);
	ll.disp();
	ll.revLinkedList();
	ll.disp();
	return 0;
}