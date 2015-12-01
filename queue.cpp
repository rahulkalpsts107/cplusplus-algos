//Queue
//Implement like a circular buffer.
#include<iostream>

#define MAXSIZE 10

using namespace std;
class queue
{
	int items[MAXSIZE];
	int front,rear;
public:
	queue()
	{
		front=rear=-1;
	}
	void insert(int item)
	{
		if ((rear+1)%MAXSIZE == front)
		{
			cout<<"Overflow !"<<endl;
			return;	
		}
		else if(isQEmpty())
		{
			front = 0;//First entry so set to 0 then from here on wards advance rear
			rear = 0;
		}
		else
			rear = (rear+1)%MAXSIZE;
		items[rear] = item;
	}
	void remove()
	{
		if (isQEmpty())
			cout<<"Underflow !"<<endl;
		else if (front == rear)
			front = rear = -1;//if both are same that means we can bring it back to initial state
		else 
			front = (front +1)%MAXSIZE;
	}
	bool isQEmpty()
	{
		bool ret = false;
		if((front == -1 && rear == -1))
			ret = true;
		return ret;
	}
	void display()
	{
		if(front<rear)
		{
			int i = front;
			for(;i<=rear;i++)
				cout<<items[i]<<" ";
			cout<<endl;
		}
		else if (front > rear)
		{
			int i;
			int diff = front - rear;
			for(i = front;i <= front+MAXSIZE - diff;i++ )
			{
				int idx = i;
				if (idx >= MAXSIZE) idx = idx%MAXSIZE;
				cout<<items[idx]<<" ";
			}
			cout<<endl;
			
		}
		else
		{
			if(isQEmpty())
				cout<<"empty"<<endl;
			else
				cout<<items[front]<<endl;
		}
	}
};

int main(int argc , char **argv)
{
	queue q;
	q.insert(1);
	q.insert(2);
	q.insert(3);
	q.insert(4);
	q.display();
	q.remove();
	q.remove();
	q.remove();
	q.remove();
	q.remove();
	q.display();
	return 0;
}
