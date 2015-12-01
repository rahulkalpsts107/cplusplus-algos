//Find next greater number with same set of digits
//Given a number n, find the smallest number that has same set of digits as n and is greater than n. 
//If x is the greatest possible number with its set of digits, then print “not possible”.

#include<iostream>
#include<string.h>

using namespace std;

int fact(int i)
{
	int ret;
	if (i == 0)
		ret = 1;
	else if (i == 1)
		ret = 1;
	else
		return fact(i-1)*i;
}

void printAllCombinations(char * str , int start ,int end)
{
	char *temp = str;
	int multiple = pow(10,end-start)
	int currPosition = 0;
	while(temp!=NULL)
	{
		int swaps = end-start;
		int i =0;
		for(;i<swaps;i++)
		{
			if (i != currPosition)
			{
				char arr[end-start+1]={0};
				
			}
		}
		currPosition++;
	}
}

int retNextHighes(char *str)
{
	int len = strlen(str);
	char *temp = str;
	int i =0;
	int num = atoi(str);
	printAllCombinations("789",0,2)
}

int main(int argc , char **argv)
{
	char str[] = "218765";
	retNextHighes(str);
	
}

