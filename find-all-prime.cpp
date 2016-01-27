//Find all prime numbers between 1...N
#include <iostream>
#include <vector>
using namespace std;

void printAll(int N ,vector<int> &primeNums)
{
	for(int i = 1 ; i<=N ;i++)
	{
		bool isPrime = true;
		for(int j = 1; j<=i ;j++)
		{
			if(i%j ==0 && j!=i && j!= 1)
			{
				isPrime =false;
				break;
			}
		}
		if(isPrime)
		{
			cout<<i<<", ";
			primeNums.push_back(i);
		}
	}
	cout<<endl;
}

int main(int argc ,char **argv)
{
	int N = 100;
	vector<int> primeNums;
	printAll(N ,primeNums);
	cout<<"largest is "<<primeNums[primeNums.size()-1]<<endl;
	return 0;
}