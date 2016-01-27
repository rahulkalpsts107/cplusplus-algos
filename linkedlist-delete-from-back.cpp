//Given a singly linked list, find the kth element from the back and delete it.  

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

	void deleteFromBack(int k)
	{
		if (size ==0)
			return;
		else if (size == 1)
		{
			if (k == 1)
			{
				delete(head);
				head = NULL;
				decSize();
			}
		}
		else if (k > size)
			return;
		else
		{
			int times = size - k+1;
			Node *temp = head;
			while(++times && temp)
				temp = temp->next;
			Node *tobeDeleted = temp->next;
			temp->next = tobeDeleted->next;
			delete(tobeDeleted);
			decSize();
			if(size == 1)
				head = temp;
		}
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

	Node * reverseLinkedList(Node *curr)
	{
		if(curr == NULL)
			return NULL;
		else if(curr->next == NULL)
		{
			head = curr;
			return curr;
		}
		else
		{
			Node *t = reverseLinkedList(curr->next);
			t->next = curr;
			cout<<t->data<<" next = "<<curr->data<<endl;
			curr->next=NULL;
			return curr;
		}
	}
};


int main(int argc ,char **argv)
{
	LinkedList ll;
	ll.insert(1);
	ll.insert(2);
	ll.insert(3);
	ll.insert(4);
	ll.insert(5);
	//ll.deleteFromBack(4);
	ll.disp();
	Node * node = ll.reverseLinkedList(ll.head);
	ll.disp();
	return 0;
}