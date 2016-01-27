//Implement a function void reversefchar* str) in Cor C++ which reverses a null-terminated
//string.

#include <iostream>

using namespace std;

void reverse(char *str)
{
	int len = strlen(str);
	if (len == 1)
		return;
	else
	{
		for (int i=0 ,j=len-1 ; j-i>=1 ; i++,j--)
		{
			cout<<i<<", "<<j<<endl;
			char temp = str[i];
			str[i] = str[j];
			str[j] = temp;
		}
	}
}

int main(int argc ,char **argv)
{
	char s[10] = "nyu";
	reverse(&s[0]);
	cout<<"the reverse is "<<s<<endl;
	return 0;
}