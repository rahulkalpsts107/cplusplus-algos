//Sort a partially sorted linked list

//1-99-1000 2-5-999

//1 -2 -5- 99 - 999 -1000
#include<iostream>

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
};

Node * returnDividePoint(Node *head)
{
	if(head == NULL)
		return head;
	else
	{
		while(head->next)
		{
			if(head->data <= head->next->data)
				head = head->next;
			else
			{
				break;
			}
		}		
		return head;
	}
}

Node *merge(Node *firstStart , Node *firstEnd , Node *secondStart ,Node *secondEnd)
{
	Node *head = NULL;
	Node *temp =head;
	while(1)
	{
		if(firstStart->data <= secondStart->data)
		{
			if(temp ==NULL)
				temp = head = firstStart;
			else
			{
				temp->next = firstStart;
				temp = temp->next ;
			}
			if(firstStart == firstEnd)
			{
				firstStart = NULL;
				break;
			}
			else
				firstStart = firstStart->next;
		}
		else
		{
			if(temp ==NULL)
				head = temp= secondStart;
			else
			{
				temp->next = secondStart;
				temp = temp->next ;
			}
			if(secondStart == secondEnd)
			{
				secondStart = NULL;
				break;
			}
			else
				secondStart = secondStart->next;
		}
	}
	Node *remaining = NULL;
	remaining = firstStart != NULL ? firstStart:secondStart;
	while(remaining)
	{
		temp->next = remaining;
		temp =temp->next;
		remaining = remaining->next;
	}
	temp->next=NULL;
	return head;
}

Node * sortList(Node *head)
{
	Node *firstStart = head;
	Node *firstEnd = returnDividePoint(head);
	Node *secondStart = NULL;
	Node *secondEnd = NULL;
	if(firstEnd)
	{
		if(firstEnd->next)
		{
			secondStart = firstEnd->next;
			Node *temp = secondStart;
			while(temp->next != NULL)
				temp=temp->next;
			secondEnd = temp;
			firstEnd->next = NULL;
			secondEnd->next = NULL;
			head = merge(firstStart,firstEnd,secondStart,secondEnd);
		}
	}
	else
		cout<<"empty"<<endl;
	return head;
}

int main(int argc ,char **argv)
{
	Node head(1);
	Node second(99);
	Node third(1000);
	Node four(2);
	Node five(5);
	Node six(999);
	head.next = &second;
	second.next =&third;
	third.next=&four;
	four.next=&five;
	five.next=&six;
	six.next=NULL;
	Node *h = sortList(&head);
	while(h != NULL)
	{
		cout<<h->data<<endl;
		h=h->next;
	}
	return 0;
}
