//sort-rotated-array-problem
#include<iostream>
#include<cmath>
using namespace std;

int modifiedBinSearch(int *arr,int start, int end)
{
	int ret = -1;
	if(end < start)
		ret = -1;
	else if(end == start)
		ret = -1;
	else
	{
		int mid = start + (end -start)/2;
		if(arr[mid+1] <arr[mid])
			ret = mid+1;
		if(arr[mid] <arr[mid-1])
			ret = mid;
		if(ret == -1)
		if(arr[end] > arr[mid])
			ret = modifiedBinSearch(arr,start,mid-1);
		else
			ret = modifiedBinSearch(arr,mid+1,end);
	}
	return ret;
}
	
void sortRotatedArray(int *arr ,int size)
{
	int resetPoint = modifiedBinSearch(arr,0,size);
	if(resetPoint != -1)
	{
		int curr = resetPoint;
		int counter = size;
		while(counter >= 0)
		{
			cout<<arr[curr]<<", "<<endl;
			if(curr == size )
				curr = curr%(size);
			else
				curr++;
			--counter;
		}
	}
	else
		cout<<"already sorted"<<endl;
}

int main(int argc,char **argv)
{
	int arr[] = {1,2};
	int size = sizeof(arr)/sizeof(arr[0]);
	sortRotatedArray(arr,size-1);
	return 0;
}