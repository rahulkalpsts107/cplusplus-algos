//Eg : Input : teeterson      
//Output : r, as it is the first element which is non repetitive. 
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;

struct Count
{
	int count;
	int index;
};

char retNotRepeatingElement(char * inp)
{
	struct Count *charCount = (Count *)calloc(sizeof(Count) ,256);
	int i;
	char ret = -1;
	char *input = inp;
	for(i=0;*(input);i++)
	{
		cout<<int(*input)<<endl;
		if(charCount[*input].count== 0)
			charCount[*input].index = i;
		charCount[*input].count++ ;
		cout<<charCount[*input].count<<" : "<<charCount[*input].index<<endl;
		++input;
	}
	for(i=0;i<256;i++)
	{
		if(charCount[i].count == 1)	
		{
			ret = inp[charCount[i].index];
			break;
		}
	}
	return ret;
}

int main(int argc,char **argv)
{
	char input[] = "geeksforgeeks";
	char ret = retNotRepeatingElement(input);
	cout<<"first non repeating is "<<ret<<endl;//o(nlogn)
	return 0;
}
