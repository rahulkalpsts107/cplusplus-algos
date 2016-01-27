//Elements from 1 to N , where there is a duplicate, find that in O(N)
#include <iostream>

using namespace std;

int returnDuplicate(int a[] ,int size)
{
	bool flags[size];
	int ret = -1;
	for(int i = 0 ; i< size ;i++)
		flags[i] = false;

	for(int i = 0 ;i <size ;i++)
	{
		if (flags[a[i]] == false)
			 flags[a[i]] = true;
		else
		{
			ret = a[i];
			break;
		}
	}	
	return ret;
}

int main(int argc , char **argv)
{
	int a[6] = {5,4,3,4,2,1};
	int size = sizeof a/sizeof(a[0]);
	int dup = returnDuplicate(a,size);
	if(dup == -1)
		cout<<"no duplicates "<<endl;
	else
		cout<<"duplicate is "<<dup<<endl;
	return 0;	
}