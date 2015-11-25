#include<iostream>
using namespace std;

//Given two arrays of ints that are sets, create a function to merge them to create a new set. 

//A set must pass on these three conditions: 
//- All values are positive 
//- Sorted 
//- Non-duplicates

int s1[] = {4,6,8,10};
int s2[] = {0,1,3,5,7,9,23,46,72};

void unionOfSet(int s1[],int s2[],int len1, int len2,int target[])
{
	int i,j,k;
	i=j=k=0;
	while(i<len1 && j<len2)
	{
		if(s1[i]<s2[j])
		{
			target[k++] = s1[i++];
		}
		else
		{
			target[k++] = s2[j++];
		}
	}
	int *nonSentinelArr = (len1 -i)?&s1[0]:&s2[0];
	int start = (len1 -i )?i:j;
	int maxLen = (len1 -i )?len1:len2;
	while(start<maxLen)
	{
		target[k++] = nonSentinelArr[start++];
	}
}

int main(int argc, char **argv)
{
	int len1 = sizeof(s1)/sizeof(s1[0]);
	int len2 = sizeof(s2)/sizeof(s2[0]);
	int target[len1+len2]={0};
	unionOfSet(s1,s2,len1,len2,target);
	int i ;
	for(i=0;i<(len1+len2);i++)
		cout<<target[i]<<", ";
	cout<<endl;
}
