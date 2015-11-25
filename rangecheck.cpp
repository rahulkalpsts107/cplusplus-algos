#include <iostream>
using namespace std;

int main() {
	unsigned int low = 10;
	unsigned int high =100;
	unsigned int x = 5;
	signed int w = x-low;
	cout<<w<<endl;
	int res = (w <= unsigned(high -low));
	cout<<res<<endl;
	// your code goes here
	return 0;
}