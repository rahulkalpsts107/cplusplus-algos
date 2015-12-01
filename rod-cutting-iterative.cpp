// A Dynamic Programming solution for Rod cutting problem
#include<stdio.h>
#include<limits.h>
#include<iostream>

using namespace std;
 
// A utility function to get the maximum of two integers
int max(int a, int b) { return (a > b)? a : b;}
 
/* Returns the best obtainable price for a rod of length n and
   price[] as prices of different pieces */
int cutRod(int price[], int n)
{
   int val[n+1];
   val[0] = 0;
   int i, j;
 
   // Build the table val[] in bottom up manner and return the last entry
   // from the table
   for (i = 1; i<=n; i++)
   {
   		if(price[i] == -1) continue;
       int max_val = INT_MIN;
       for (j = 0; j < i; j++)
       {
       		int pries = price[j];
       		if(pries == -1) continue;
       		max_val = max(max_val, pries + val[i-j-1]);
	   }
       val[i] = max_val;
       int t;
       for(t=0;t<=n;t++)
       cout<<"-> "<<val[t]<<endl;
       cout<<"--------------"<<endl;
   }
   return val[n];
}
 
/* Driver program to test above functions */
int main()
{
    //int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int arr[] = {7,7,-1,21,26,-1,39,-1,53};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Maximum Obtainable Value is %d\n", cutRod(arr, size));
    getchar();
    return 0;
}
