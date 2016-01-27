//Write a function to reverse a string.

#include <iostream>

using namespace std;

int stringLen(const char *inp)
{
	int count = 0;
	while(*inp++ != '\0') count++;
	return count;
}

void reverseString(const char * inp , char * output)
{
	int len = stringLen(inp);
	int curr = len-1;
	while(curr >= 0)
	{
		output[len - curr - 1] = *(inp+curr);
		curr-=1;
	}
	output[len] = '\0';
}


int main(int argc , char **argv)
{
	char input[] = "Madam, I'm Adam";
	char output[255]={0};
	reverseString(input,output);
	cout<<"output "<<output<<endl;
	return 0;
}