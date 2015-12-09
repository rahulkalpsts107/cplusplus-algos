#include<iostream>

using namespace std;

class Node
{
public:
	Node(int dat):data(dat){ next = NULL;}
	int data;
	Node *next;
};

class LinkedList
{
public:
	Node* head;
	Node *tail;
	int size;
	LinkedList()
	{
		size = 0;
		head = NULL;
		tail = NULL;
	}

	void addToHead(int data)
	{
		if(size++ == 0)
			head = tail =new Node(data);
		else
		{
			tail->next = new Node(data);
			tail = tail->next;
			++size;	
		}
	}

	void display()
	{
		Node* temp = head;
		while(temp!=NULL)
		{
			cout<<temp->data<<" , ";
			temp=temp->next;
		}
		cout<<endl;
	}
};

void returnUnion(Node* list1 ,Node* list2 ,LinkedList &list3)
{
	int i,j;
	while( list1!= NULL || list2!= NULL)
	{
		if(list1->data < list2->data)
		{
			list3.addToHead(list1->data);
			list1 = list1->next;
		}
		else if(list2->data < list1->data)
		{
			list3.addToHead(list2->data);
			list2 = list2->next;
		}
		else 
		{
			list3.addToHead(list2->data);
			list1 = list1->next;
			list2 = list2->next;
		}
		
	}
	Node *remaining = NULL;
	if(list1 != NULL)
		remaining = list1;
	if(list2 != NULL)
		remaining = list2;
	while(remaining != NULL)
	{
		list3.addToHead(remaining->data);
	}
	remaining = remaining->next;
}

//Find intersection and union of singly linked list
int main(int argc,char **argv)
{
	LinkedList ll;
	ll.addToHead(1);
	ll.addToHead(2);
	ll.addToHead(3);
	ll.addToHead(4);
	ll.addToHead(5);
	ll.display();
	LinkedList ll1;
	ll1.addToHead(1);
	ll1.addToHead(5);
	ll1.addToHead(8);
	ll1.addToHead(9);
	ll1.display();
	LinkedList ll2;
	returnUnion(ll.head,ll1.head,ll2);
	ll2.display();
	return 0;
}