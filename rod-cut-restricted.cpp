#include<stdio.h>
#include<limits.h>
#include<iostream>

using namespace std;

//If the algorithm, in addition, is given the fact that the prices are subadditive (meaning that
//pi+j = pi + pj for all i, j = 0 with i + j = n

int cutRod(int price[], int n)
{
   int val[n+1];
   val[0] = 0;
   int i, j;
   cout<<"i "<<i<<endl;
   int max_val = INT_MIN;
   for (j = 1; j <=n; j++)
   {
     max_val = max(max_val, price[j-1] + val[j-1]);
     cout<<"j "<<j<<" price "<<j<<" val "<<j+1<<" max val "<<max_val<<endl;
     val[j] = max_val;
	}
   return val[n];
}

int main()
{
    int arr[] = {7,14,21,28,28};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Maximum Obtainable Value is %d\n", cutRod(arr, size));
    getchar();
    return 0;
}
