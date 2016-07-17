//Write function to compute Nth fibonacci number

#include <iostream>
using namespace std;
int fibo(int num)
{
	int runningFibo = 0;
	int arr[num];
	for(int i = 0 ; i<= num ; i++)
	{
		if (i== 0)
			arr[i] = 0;
		else if (i == 1)
			arr[i] = 1;
		else 
			arr[i] = arr[i-1] + arr[i-2];
	}
	runningFibo = arr[num-1];
	return runningFibo;
}

int main(int argc , char **argv)
{
	int num = 11;
  	cout<<"fibo of "<<num<<" is "<<fibo(num)<<endl;




  	
	return 0;
}