//two stacks using one array
#include<iostream>

using namespace std;

class TwoStacks
{
	int *arr;
	int *stackHead;
	int size ;
	
public:
	TwoStacks(int size)
	{
		this->size = size;
		arr = new int[size];
		stackHead = new int[2];
		stackHead[0] = -1;
		stackHead[1] = size;
	}
	
	void push(int stackNo,int item)
	{
		cout<<"Enter"<<endl;
		if(stackNo == 0)
		{
			if(stackHead[stackNo] +1 <stackHead[1])
				arr[++stackHead[stackNo]] = item;
			else
				cout<<"Overflow"<<endl;
		}
		else if(stackNo == 1)
		{
			if(stackHead[stackNo] +1 >stackHead[0])
				arr[--stackHead[stackNo]] = item;
			else
				cout<<"Overflow"<<endl;
		}
		else
			cout<<"invalid stack"<<endl;
		cout<<"Exit"<<endl;
	}
	
	int pop(int stackNo)
	{
		int item =-1;
		if(stackNo == 0)
		{
			if (stackHead[stackNo]	 == -1)
				cout<<"Under flow !"<<endl;
			else
				item = arr[stackHead[stackNo]--];
			
		}
		else if(stackNo == 1)
		{
			if (stackHead[stackNo]	 == size)
				cout<<"Under flow !"<<endl;
			else
				item = arr[stackHead[stackNo]++];
		}
		else
			cout<<"invalid stack"<<endl;
		return item;
	}
	
	bool isEmpty(int stackNo)
	{
		bool ret = false;
		if(stackNo == 0)
		{
			if(stackHead[stackNo]== -1)
				ret = true;
		}
		else if(stackNo == 1)
		{
			if(stackHead[stackNo]== size)
				ret = true;
		}
		else
			cout<<"invalid stack"<<endl;
		return ret;
	}
	
	void printStacks()
	{
		cout<<"stack 1"<<endl;
		int i;
		if(stackHead[0]!=-1)
		{
			for(i = stackHead[0];i>=0 ; i--)
				cout<<arr[i]<<", ";
			cout<<endl;
		}
		else
			cout<<"stack 1 empty"<<endl;
		if(stackHead[1]!=size)
		{
			for(i = stackHead[1];i<size ; i++)
				cout<<arr[i]<<", ";
			cout<<endl;
		}

	}
};

int main(int argc,char **argv)
{
	int size =5;
	TwoStacks s(size);
	s.push(1,5);
	s.push(1,10);
	//cout<<s.pop(1)<<endl;
	//cout<<s.pop(1)<<endl;
	//cout<<s.pop(1)<<endl;
	s.push(0,4);
	s.push(0,3);
	s.push(0,2);
	s.push(0,1);
	s.printStacks();
	s.push(1,13);
	s.printStacks();
	return 0;
}

