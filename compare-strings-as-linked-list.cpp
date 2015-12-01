#include<iostream>

//Compare two strings represented as linked lists
//Given two linked lists, represented as linked lists 
//(every character is a node in linked list). 
//Write a function compare() that works similar to strcmp(), i.e., 
//it returns 0 if both strings are same, 
//1 if first linked list is lexicographically greater, and 
//-1 if second string is lexicographically greater.

//Bruteforce
using namespace std;
class Node
{
public:
	Node *next;
	char data;
	Node(char data)
	{
		this->next = NULL;
		this->data = data;
	}
};

class List
{
public:
	Node *head;
	int size;
	Node *tail;
	List()
	{
		head = NULL;
		tail = NULL;
		size=0;
	}
	
	void insertToTail(char data)
	{
		Node *temp = new Node(data);
		size++;
		if(head == NULL)
		{
			head = tail = temp;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
	}
	void display()
	{
		Node *temp = head;
		while(temp != NULL)
		{
			cout<<temp->data<<", ";
			temp=temp->next;
		}
		cout<<endl;
	}
};

int list_strcmp(List *first,List *second)
{
	Node *temp1 = first->head;
	Node *temp2 = second->head;	
	int score1,score2,score3;
	int ret =0;
	score1=score2=score3=0;
	for(;(temp1 != NULL && temp2 != NULL);temp1=temp1->next,temp2=temp2->next)
	{
		if(temp1->data > temp2->data)
			score1++;
		else if(temp2->data > temp1->data)
			score2++;
	}
	if(score1 > score2)
		ret = 1;
	else if (score2 >score1)
		ret =-1;
	else
		if(temp1 == NULL && temp2 == NULL)
			ret = 0;
		else
		{
			first->size - second->size > 0?ret=1:ret=-1 ;
		}
	return ret;
}

int main(int argc,char **argv)
{
	List str = List();
	//str.insertToTail('a');
	//str.insertToTail('b');
	//str.insertToTail('c');
	//str.insertToTail('d');
	//str.insertToTail('e');
	str.display();
	List str1 = List();
	str1.insertToTail('a');
	str1.insertToTail('b');
	//str1.insertToTail('c');
	str1.display();
	cout<<"Comparision = "<<list_strcmp(&str,&str1)<<endl;
	return 0;
}
