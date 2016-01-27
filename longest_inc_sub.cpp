//Longest increasing sub sequenece

#include <iostream>

using namespace std;

void maxSubSequence(int arr[] ,int idx ,int memo[] ,int lens[])
{
	if(idx == 0)
		return ;
	else
	{
		for(int i=1; i<=idx ;i++)
		{
			maxSubSequence(arr,idx-1,memo,lens);
			if(arr[i]>arr[i-1] && memo[i] < memo[i-1] + arr[i])
			{
				memo[i] = arr[i] +memo[i-1];
				lens[i]=lens[i-1]+1;
			}
		}
	}
	return ;
}

int main()
{
	int arr[] = { 1,101,2,3,100,4,5 };
    int n = sizeof(arr)/sizeof(arr[0]);
    int memo[n];
    int lens[n];
    for(int i =0; i<n ;i++)
    	memo[i] = arr[i];
    for(int i=0 ;i<n ;i++)
    	lens[i]=1;
    maxSubSequence(arr,n-1,memo,lens);
    cout<<"max len of sub seqeuence is "<<lens[n-1]<<endl;
    int max =0;
    for(int i=0 ; i<n ;i++)
    {
    	if(max <= memo[i])
    		max = memo[i];
    	cout<<memo[i]<<endl;
    }
    cout<<"max val of sub seqeuence is "<<max<<endl;
	return 0;
}