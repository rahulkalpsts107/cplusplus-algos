//Write a program that will read an array of lines (strings with blank spaces), 
//string s and positive integer k, and then prints new //array og lines such that string s is added on k-th position in every line. New array should only contains uppercase letters.

#include <iostream>
#include <vector>
#include <string.h>

#define LINES_SIZE 255

using namespace std;

void read(vector<string> &lines , string &rep ,int *pos)
{
	int num =0;
	cout<<"Enter the num of lines"<<endl;
	cin>>num;
	cout<<"Enter the lines"<<endl;
	while(num)
	{
		string s;
		cin>>s;
		lines.push_back(s);
		num--;
	}
	cout<<"Enter the replacement string "<<endl;
	cin>>rep;
	cout<<"Enter the position"<<endl;
	cin>>*pos;
}

char ** cread(int *pos, char *rep ,int *numLines)
{
	int num =0;
	cout<<"Enter the num of lines"<<endl;
	cin>>num;
	cout<<"Enter the lines"<<endl;
	char **linesArr ;
	linesArr = (char **) malloc(sizeof(char *) * num);
	int i =0;
	*numLines = num;
	if(num)
	{
		while(i != num)
		{
			char *arr = (char *)malloc(sizeof(char) * LINES_SIZE );
			cin>>arr;
			linesArr[i] = arr;
			i++;
		}
		cout<<"Enter the replacement string "<<endl;
		cin>>rep;
		cout<<"Enter the position"<<endl;
		cin>>*pos;
	}
	else
	{
		cout<<"invalid num"<<endl;
	}
	return linesArr;
}

char ** insert(char **cLines , int numberLines , char *rep ,int pos)
{
	char **output ;
	output = (char **) malloc(sizeof(char *) *numberLines);
	int count =0;
	int repLen = strlen(rep);
	while(count < numberLines)
	{
		int len = strlen(cLines[count]);
		int targetLen = repLen+len+1;
		char *newLine = (char *) malloc(sizeof(char) * targetLen);
		int mainCnt =0;
		int newCnt =0;
		for(; newCnt<pos ;newCnt++,mainCnt++)
		{
			newLine[newCnt] = toupper(cLines[count][mainCnt]);
		}
		for(int repCnt =0; repCnt<repLen ;repCnt++,newCnt++)
		{
			newLine[newCnt] =toupper(rep[repCnt]);
		}
		for(; newCnt<targetLen ;newCnt++,mainCnt++)
		{
			newLine[newCnt] = toupper(cLines[count][mainCnt]);
		}
		newLine[newCnt] ='\0';
		output[count] = newLine;
		count++;
	}
	return output;
}

int main()
{
	int pos =-1;
	char crep[255];
	int numLines =0;
	char **clines  = cread(&pos, &crep[0] ,&numLines);
	char **outputLines = insert(clines , numLines , crep , pos);
	cout<<"output is "<<endl;
	for(int i = 0; i<numLines ;i++)
	{
		cout<<outputLines[i]<<endl;
	}

	return 0;
}