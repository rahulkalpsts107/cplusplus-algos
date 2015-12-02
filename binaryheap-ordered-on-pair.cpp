//binary heap ordered on pair
#include<iostream>
#include<cmath>
using namespace std;

int getLevel(int idx,int size);

class Pair
{
public:
	Pair()
	{
	}
	int price;
	int quality;
};

class PairPriorityQueue
{
private:
	int size;
	int curr;
	Pair *implicit;
	
	int parent(int i)
	{
		return ceil((float)i/2.0)-1;
	}
	
	void bubbleUpPair(int node)
	{
		int cur = node;
		cout<<"bubbleUpPair enter"<<endl;
		while(cur>=0)
		{
			cout<<"cur "<<cur<<endl;
			int par = parent(cur);
			if(par <0) break;
			int parentLevel = getLevel(par,curr+1);
			if(parentLevel%2 == 0)//make sure new entry has price higher than parent price 
			{
				cout<<"isEven"<<endl;
				if(implicit[par].price > implicit[cur].price)
				{
					//swap
					swap(implicit[par],implicit[cur]);
				}
			}
			else //make sure new entry has quality higher than parent quality 
			{
				cout<<"isOdd"<<endl;
				if(implicit[par].quality < implicit[cur].quality)
				{
					//swap
					swap(implicit[par],implicit[cur]);
				}
			}
			cur = par;//both should stop so go till root
		}
	}

public:
	friend ostream & operator<<(ostream &os, PairPriorityQueue *queue);
	PairPriorityQueue(int size)
	{
		this->size = size;
		curr = -1;
		implicit = new Pair[size];
	}
	
	~PairPriorityQueue()
	{
		delete implicit;
	}
	
	void insert(int price, int quality)
	{
		if(curr >= size -1)
		{
			cout<<"pq over flow !"<<endl;
		}
		else
		{
			curr++;
			implicit[curr].price = price;
			implicit[curr].quality = quality;
			cout<<"curr"<<curr<<endl;
			if(curr >0)
				bubbleUpPair(curr);
			cout<<"insert exit"<<endl;
		}
	}
	
	string toString()
	{
		cout<<"enter"<<endl;
		string ret;
		int i = 0;
		while(i<=curr)
		{
			char buff[50];
			sprintf(buff,"price [%d] quality[%d],",implicit[i].price,implicit[i].quality);
			ret +=string(buff);
			i++;
		}
		cout<<"exit"<<endl;
		return ret;
	}
};

int getLevel(int idx,int size)
{
	int level = 0;
	while(idx != 0)
	{
		idx--;
		size = (size-1)/2;
		idx = idx%size;
		level++;
	}
	return level;
}

void swap(Pair &a, Pair &b)
{
	int temp = a.price;
	a.price = b.price;
	b.price = temp;
	temp = a.quality;
	a.quality = b.quality;
	b.quality = temp;
}

ostream & operator<<(ostream &os, PairPriorityQueue & queue)
{	
    return os << queue.toString()<<endl;
}

int main(int argc,char **argv)
{
	int size = 5;
	PairPriorityQueue pq = PairPriorityQueue(size);
	pq.insert(1,1);
	cout<<pq<<endl;	
	pq.insert(0,10);
	cout<<pq<<endl;	
	pq.insert(2,8);
	cout<<pq<<endl;	
	pq.insert(3,7);
	cout<<pq<<endl;	
	pq.insert(5,9);
	cout<<pq<<endl;	
	return 0;	
}
