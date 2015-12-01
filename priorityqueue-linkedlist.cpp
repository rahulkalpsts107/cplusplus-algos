#include<iostream>
#include<sstream>

//Priority queue as a unsorted linked list
//insert O(1)
//extractmax O(n)
//findMax O(n)

using namespace std;
class Node
{		
public:
	Node * next;
	int data;
	int priority;
	Node(int data,int priority)
	{
		this->next = NULL;
		this->data = data;
		this->priority = priority;
	}
	string toString()
	{
		ostringstream o;
		o<<" data "<<this->data<<" - priority - "<<this->priority<<", ";
		return o.str();
	}
};

class PriorityQueue
{
public:
	Node * head;
	Node * tail;
	int size;
private:
	void insertToTail(int data,int priority)
	{
		if(size ==0)
		{
			head = tail = new Node(data,priority);
			head->next = NULL;
		}
		else if (size == 1)
		{
			head = new Node(data,priority);;
			head->next = tail;
		}
		else 
		{
			Node *temp = head;
			head = new Node(data,priority);;
			head->next = temp;
		}
		size++;
	}
	
	int removeNode(Node *node)
	{
		Node *fast = head;
		Node *slow = NULL;
		int data;
		while(fast != node)
		{
			slow = fast;
			fast = fast->next;
		}
		if(slow != NULL)
		{
			slow->next = fast->next;
			data = fast->data;
			delete fast;
			--size;
			if(size == 1)
				head = tail = slow;
		}
		else
		{
			cout<<"here"<<endl;
			Node *temp = head;
			data = head->data;
			--size;
			if(size == 0)
				head = tail = NULL;
			else
				head = temp->next;
			delete temp;
		}
		return data;
	}
	
public:
	friend ostream & operator<<(ostream &os, PriorityQueue *queue);
	
	PriorityQueue()
	{
		head = NULL;
		tail = NULL;
		size = 0;
	}
	
	void insert(int data,int priority)
	{
		insertToTail(data,priority);
	}
	
	int extractMax()
	{
		Node *max = findMax();
		if(max != NULL)
			return removeNode(max);
		else 
			return -1;
	}
	
	Node * findMax()
	{	
		Node *temp = head;
		Node *max = temp;
		while(temp!=NULL)
		{
			if((temp->priority) > (max->priority))
				max=temp;
			temp = temp->next;
		}
		return max;
	}
	
};

ostream & operator<<(ostream &os, PriorityQueue & queue)
{
	string ret;
	Node *temp = queue.head;
	while(temp!=NULL)
	{
		ret +=temp->toString();
		temp = temp->next;
	}
    return os << ret.c_str()<<endl;
}

int main(int argc ,char **argv)
{
	PriorityQueue queue;
	queue.insert(1,4);
	queue.insert(2,1);
	queue.insert(4,6);
	queue.insert(3,12);
	cout<<queue<<endl;
	cout<<"max = "<<queue.extractMax()<<endl;
	cout<<queue<<endl;
	cout<<"max = "<<queue.extractMax()<<endl;
	cout<<queue<<endl;
	cout<<"max = "<<queue.extractMax()<<endl;
	cout<<queue<<endl;
	cout<<"max = "<<queue.extractMax()<<endl;
	cout<<queue<<endl;
	cout<<"max = "<<queue.extractMax()<<endl;
	cout<<queue<<endl;
	queue.insert(1,4);
	queue.insert(2,1);
	queue.insert(4,6);
	queue.insert(3,12);
	cout<<queue<<endl;
	cout<<"max = "<<queue.extractMax()<<endl;
	cout<<queue<<endl;
}
