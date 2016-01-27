//Merge two sorted linked lists such that merged list is in reverse order
//Input:  a: 5->10->15->40
//b: 2->3->20 

#include<iostream>
#include<sstream>

using namespace std;
class Node
{		
public:
	Node * next;
	int data;
	Node(int data)
	{
		this->next = NULL;
		this->data = data;
	}
	string toString()
	{
		ostringstream o;
		o<<" "<<this->data<<", ";
		return o.str();
	}
};

class LinkedList
{
public:
	Node * head;
	Node * tail;
	int size;
private:
	
public:
	friend ostream & operator<<(ostream &os, LinkedList *list);
	
	LinkedList()
	{
		head = NULL;
		tail = NULL;
		size = 0;
	}
	
	void insertToTail(int data)
	{
		if(size ==0)
		{
			head = tail = new Node(data);
			head->next = NULL;
		}
		else if (size == 1)
		{
			head = new Node(data);
			head->next = tail;
		}
		else 
		{
			Node *temp = head;
			head = new Node(data);
			head->next = temp;
		}
		size++;
	}
	
	void listCopy(int *data,int size)
	{
		int i = 0;
		for(;i<size;i++)
			insertToTail(data[i]);
	}
};

void arrReverse(int *arr,int size)
{
	if (size == 1)
		return;
	else
	{
		int i =0;
		int j = size-1;
		for(i=0;i!=j;i++,j--)
		{
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
}

void merge(Node *head1, Node *head2, int out[])
{
	int i =0;
	for(;head1!=NULL && head2!=NULL;)
	{
		if(head1->data <= head2->data )
		{
			out[i++] = head1->data;
			head1 = head1->next;
		}	
		else if(head2->data < head1->data )
		{
			out[i++] = head2->data;
			head2 = head2->next;
		}
	}
	Node *temp;
	if(head1 != NULL)
		temp = head1;
	else if(head2 != NULL)
		temp = head2;
	else
		return;
	while(temp != NULL)
	{
		out[i++] = temp->data;
		temp = temp->next;
	}
}

Node * inMerge(Node *h1 , Node *h2)
{
	Node *head = NULL;
	Node *list = NULL;
	while(h1 && h2)
	{
		cout<<"hi "<<h1->data<<" "<<h2->data<<endl;
		if(h1->data < h2->data)
		{
			if(list == NULL)
				head = list = h1;
			else
				list->next = h1;
			list = h1;
			h1= h1->next;
		}
		else if(h2->data < h1->data)
		{
			if(list == NULL)
				head = list = h2;
			else
				list->next = h2;
			list = h2;
			h2= h2->next;
		}
		else 
		{
			if(list == NULL)
				head = list = h1;
			else
				list->next = h1;
			list = h1;
			h1= h1->next;
			h2= h2->next;
		}
	}
	if(h1)
	{
		while(h1)
		{
			list->next = h1;
			list = h1;
			h1=h1->next;
		}
	}
	else if(h2)
	{
		while(h2)
		{
			list->next = h2;
			list = h2;
			h2=h2->next;
		}
	}
	else{}
	if(list != NULL)
		list->next = NULL;
	return head;
}

ostream & operator<<(ostream &os, LinkedList& node)
{
	string ret;
	Node *temp = node.head;
	while(temp!=NULL)
	{
		ret +=temp->toString();
		temp = temp->next;
	}
    return os << ret.c_str()<<endl;
}
int main(int argc,char **argv)
{
	LinkedList list1;
	list1.insertToTail(40);
	list1.insertToTail(15);
	list1.insertToTail(10);
	list1.insertToTail(5);
	LinkedList list2;
	list2.insertToTail(20);
	list2.insertToTail(3);
	list2.insertToTail(2);
	cout<<list1<<endl;
	cout<<list2<<endl;
	int *arr = new int[list1.size+list2.size];
	Node * n = inMerge(list1.head,list2.head);
	//merge(list1.head,list2.head,arr);
	//arrReverse(arr,list1.size+list2.size);//No need of reverse , since we are adding to head of linked list so it will be any ways reverse sorted
	//just merge and add to head of Linked list
	//LinkedList list3;
	//list3.listCopy(arr,list1.size+list2.size);
	while(n)
	{
		cout<<n->data<<endl;
		n=n->next;
	}

	return 0;
}
