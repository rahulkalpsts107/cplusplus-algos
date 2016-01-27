//Write a method to replace all spaces in a string with '%20'. You may assume that the
//string has sufficient space at the end of the string to hold the additional characters,
//and that you are given the "true" length of the string. (Note: if implementing in Java,
//please use a character array so that you can perform this operation in place.)

#include <iostream>

using namespace std;

void shift(char *str ,int start ,int end ,int shift)
{
	if(end -start <= 0) return;
	while(end>=start)
	{
		str[end+shift] = str[end];
		end--;
	}
}

void replaceWhiteSpace(char *str ,char *insert)
{
	int len = strlen(str);
	int insLen = strlen(insert);
	int i=0;
	while(i<len)
	{
		if(str[i] == ' ')
		{
			shift(str,i,len,insLen-1);
			int temp =0;
			int j=i;
			while(temp < insLen)
				str[j++] = insert[temp++];
			i+=insLen;
			len+=insLen;
			cout<<"intr "<<str<<":"<<i<<endl;
		}
		else
			i++;
	}
}

int main(int argc ,char **argv)
{
	char inp[100] = "ab cd efg  hi j";
	//char inp[100] = "a  ";
	char ins[4] = "%20";
	replaceWhiteSpace(inp,ins);
	cout<<inp<<endl;
	return 0;
}