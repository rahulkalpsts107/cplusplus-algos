#include<iostream>
#include<string>
#include<sstream>
#include<cmath>
#include<stack>

using namespace std;
class Node
{		
public:
	Node * next;
	int data;
	Node(const Node &node)
	{
		this->data = node.data;
		this->next = node.next;
	}
	Node(Node*next,int data)
	{
		this->next = next;
		this->data = data;
	}
	string toString()
	{
		ostringstream o;
		o<<" "<<this->data<<" "<<endl;
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
	
	void incSize()
	{
		this->size++;
	}
	void decSize()
	{
		this->size--;
	}
public:
	friend ostream & operator<<(ostream &os, LinkedList *list);
	LinkedList(const LinkedList &ll)
	{
		cout<<"copy called"<<endl;
		head = NULL;
		tail = NULL;
		size = 0;
		if(ll.size == 0)
		{
			head = tail = NULL;
			size = 0;
		}
		else if(ll.size > 0)
		{
			Node *temp1 = ll.head;
			insertBeginning(temp1->data);
			temp1 = temp1->next;
			while(temp1)
			{
				insertTail(temp1->data);
				temp1 = temp1->next;
			}
		}
		else
		{
			cout<<"invalid size cant copy"<<endl;
		}
	}
	LinkedList()
	{
		head = NULL;
		tail = NULL;
		size = 0;
	}
	void insertBeginning(int data)
	{
		if(size == 0)
			head = tail = new Node(NULL,data);
		else if(size == 1)
		{	
			head = new Node(tail = head,data);
		}
		else
		{
			head = new Node(head,data);
		}
		incSize();
	}
	void insertTail(int data)
	{
		incSize();
		Node * temp;
		temp = new Node(NULL,data);
		tail->next = temp;
		tail = temp;
	}
	void deleteAfter(Node *n)
	{
		Node *toBeDeleted = n->next;
		n->next = toBeDeleted->next;
		delete(toBeDeleted);
		decSize();
		if(size == 1)
			tail = n;
		
	}
	void pop()
	{
		if(size == 1)
		{
			delete(head);
			head = tail = NULL;
			decSize();
		}
		else
		{
			Node *temp = head->next;
			delete(head);
			decSize();
			if(size == 1)
				head = tail = temp;
			else head = temp;
			
		}
	}
	void reverseFromMid()
	{
		int mid = ceil(size/2);
		Node *temp = head;
		while(--mid > 0) 
			temp = temp->next;
		Node *appendNode = temp;
		temp = temp->next;
		stack<Node*> s1;
		while(temp)
		{
			s1.push(temp);
			temp = temp->next;
		}
		while(!s1.empty())
		{
			appendNode->next = s1.top();
			s1.pop();
			appendNode =appendNode->next;
		}
		appendNode->next = NULL;
		tail = appendNode;
	}
	void deleteAllOccurences(int data)
	{
		cout<<"Enter"<<endl;
		Node * pred;
		Node * succ = head;
		while(succ != NULL)
		{
			if(succ->data == data)
			{
				if(pred == NULL)
				{
					pop();
					succ = head;
				}	
				else
				{
					succ = succ->next;
					deleteAfter(pred);
				}
			}
			else
			{
				pred = succ;
				succ = succ->next;
			}
		}
	}
};

ostream & operator<<(ostream &os, LinkedList& node)
{
	string ret;
	Node *temp = node.head;
	while(temp)
	{
		ret +=temp->toString();
		temp = temp->next;
	}
    return os << ret.c_str()<<endl;
}

int main(int argc ,char **argv)
{
	LinkedList list=LinkedList();
	list.insertBeginning(1);
	list.insertBeginning(2);
	list.insertBeginning(3);
	list.insertTail(3);
	list.insertTail(5);
	list.insertBeginning(5);
	list.insertBeginning(5);
	list.insertBeginning(8);
	list.insertBeginning(9);
	cout<<list<<endl;
	LinkedList list2 = list;
	cout<<"---"<<endl;
	cout<<list2<<endl;
	list.reverseFromMid();
	cout<<"---"<<endl;
	cout<<list<<endl;
	cout<<"---**"<<endl;
	list.deleteAllOccurences(10);
	cout<<list<<endl;
	return 0;
}
