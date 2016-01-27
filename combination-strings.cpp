/* print all combinations*/
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

char A[] = {'a','b','c'}; 
int N = sizeof(A)/sizeof(A[0]); 


int main(int argc , char **argv)
{
	int Total = pow(2,N);
	for ( int i = 0; i < Total; i++ ) 
	{ 
		for ( int j = 0; j < N; j++) 
		{
			if ( 1<<j & i ) //Check if jth bit is set in i
			{
				cout << A[j]; 
			}
		} 
		cout << endl; 
	}
	return 0;
}