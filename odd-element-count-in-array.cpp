//find all numbers that occurred an odd-number of times in an array
#include<map>
#include<vector>
#include<iostream>

using namespace std;

void calculateOddCount(int *arr,int size,vector<int> &counts)
{
	map<int,int> countMap;
	int i;
	for(i=0;i<size;i++)
	{
		map<int,int>::iterator iter = countMap.find(arr[i]);
		if(iter!=countMap.end())
		{
			iter->second+=1;
		}
		else
		{
			countMap.insert(pair<int,int>(arr[i],1));
		}
	}
	map<int,int>::iterator iter;
	for (iter=countMap.begin(); iter!=countMap.end(); ++iter)
	{
		if(iter->second %2 == 1)
			counts.push_back(iter->first);
	}
	
}

int main(int argc ,char **argv)
{
	int arr[] = {5,6,4,1,5,3,2,3,6,3,1,9,5,2,4,11,11,12,11,13,12,13,12,14,13};
	vector<int> counts;
	int size = sizeof(arr)/sizeof(arr[0]);
	calculateOddCount(arr,size,counts);
	vector<int>::iterator iter;
	for (iter=counts.begin(); iter!=counts.end(); ++iter)
		cout<<*iter<<", "<<endl;
	return 0;
}
