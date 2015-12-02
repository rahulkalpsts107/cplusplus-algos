//priority-queue using binary heap
#include<iostream>
#include<sstream>
#include<cmath>
#include<stdio.h>

using namespace std;

class PriorityQueue
{
private:
	int size;
	int curr;
	int *implicit;
	
	int left(int i)
	{
		return (i<<1)+1;
	}
	
	int right(int i)
	{
		return (i<<1) +2;
	}
	
	int parent(int i)
	{
		return ceil((float)i/2.0)-1;
	}
	
	void bubbleUp(int node)
	{
		int up = node;
		while(up>=0)
		{
			cout<<"up "<<up<<endl;
			int par = parent(up);
			cout<<"par "<<par<<endl;
			if(implicit[par] < implicit[up])
			{
				int temp = implicit[par];
				implicit[par] = implicit[up];
				implicit[up] = temp;
				up = par;
			}
			else
			{
				break;
			}
		}
	}
	
	void bubbleDown(int node)
	{
		while(1)
		{
			cout<<node<<endl;
			int leftNode = left(node);
			int rightNode = right(node);
			int max = -1;
			int idx = -1;
			if(leftNode <= curr)
				if(implicit[leftNode] > implicit[node])
				{
					max = implicit[leftNode];
					idx = leftNode;
				}	
			if(rightNode <= curr)
				if(implicit[rightNode] > max)
				{
					max = implicit[rightNode];
					idx = rightNode;
				}
			if(max == -1)
				return;
			else
			{
				int temp = implicit[idx];
				implicit[idx] = implicit[node];
				implicit[node] = temp;
				node = idx;
			}
		}
	}
	
public:
	friend ostream & operator<<(ostream &os, PriorityQueue *queue);
	PriorityQueue(int size)
	{
		this->size = size;
		curr = -1;
		implicit = new int[size];
	}
	
	~PriorityQueue()
	{
		delete implicit;
	}
	
	int extractMax()
	{
		if(curr <0 )	
			return -1;
		else
		{
			int temp = implicit[0];
			implicit[0] = implicit[curr];
			implicit[curr] = temp;
			curr--;//deleted
			if(curr >0)
				bubbleDown(0);
			return temp;
		}
	}
	
	int findmax()
	{
		if(curr < 0)
			return -1;
		return implicit[0];
	}
	
	void insert(int data)
	{
		if(curr >= size -1)
		{
			cout<<"pq over flow !"<<endl;
		}
		else
		{
			implicit[++curr] = data;
			cout<<"insert at "<<curr<<endl;
			if(curr >0)
				bubbleUp(curr);
		}
	}
	
	string toString()
	{
		string ret;
		int i = 0;
		while(i<=curr)
		{
			char buff[50] ;
			sprintf(buff," %d ,",implicit[i]);
			ret +=string(buff);
			i++;
		}
		return ret;
	}
};

ostream & operator<<(ostream &os, PriorityQueue & queue)
{	
    return os << queue.toString()<<endl;
}

int main(int argc,char **argv)
{
	int size = 5;
	PriorityQueue pq = PriorityQueue(size);
	pq.insert(3);
	pq.insert(4);
	pq.insert(5);	
	pq.insert(5);
	//pq.insert(0);
	//pq.insert(8);
	cout<<pq<<endl;
	cout<<"find max = "<<pq.findmax()<<" "<<endl;
	cout<<"extracted max = "<<pq.extractMax()<<endl;
	cout<<pq<<endl;
	cout<<"extracted max = "<<pq.extractMax()<<endl;
	cout<<pq<<endl;
	cout<<"extracted max = "<<pq.extractMax()<<endl;
	cout<<pq<<endl;
	cout<<"extracted max = "<<pq.extractMax()<<endl;
	cout<<pq<<endl;
	cout<<"extracted max = "<<pq.extractMax()<<endl;
	cout<<pq<<endl;
	cout<<"extracted max = "<<pq.extractMax()<<endl;
	cout<<pq<<endl;
	pq.insert(3);
	pq.insert(4);
	pq.insert(5);	
	pq.insert(1);
	pq.insert(8);
	cout<<pq<<endl;
	return 0;	
}
