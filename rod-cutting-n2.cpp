#include<iostream>
#include<limits.h>
#include<algorithm>
//2^n
using namespace std;

int cutRod(int *price , int len)
{
	int i;
	int maxVal = INT_MIN;
	if (len<=0)
		return 0;
	cout<<"start "<<len<<endl;
	for(i=0;i<len;i++)
	{
		cout<<"recur start "<<len<<" i "<<i<<endl;
		maxVal = max(maxVal,price[i]+cutRod(price,len-i-1));
		cout<<"recur end "<<len<<" i "<<i<<" max "<<maxVal<<endl;
	}
	cout<<"end "<<len<<" max "<<maxVal<<endl;
	return maxVal;
}

int main(int argc,char **argv)
{
	//int arr[size] = {1,5,8,9,10,17,17,20};
	//int arr[] = {7,7,13,21,26,33,39,46,53};
	//int arr[] = {15,22,40,71,94,120,142,165};
	//int arr[] = {1,2,3,4,16};
	int arr[] = {7,7,13,19,26,32,38,45,52};
	int size = sizeof(arr)/sizeof(arr[0]);
	//int arr[size] = {1,5,8,10,13,17,18,22,25,30};
	//int arr[size] = {1,1,2,2,3,100};
	//int arr[size] = {1,1,2,2,4,5};
	cout<<cutRod(arr,size)<<endl;
	return 0;
}
