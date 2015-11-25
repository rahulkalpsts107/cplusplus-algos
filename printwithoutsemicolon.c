#include <iostream>
#include <cstdlib>
#include <stdio.h>
#define N 100
using namespace std;

int main() 
{
	int n = N;
	while(n && printf("%d \n",n--)){}
	return 0;
}