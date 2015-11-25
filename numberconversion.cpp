#include <stdio.h>
#include<iostream>
#include <string>
#include<sstream>
using namespace std;
int i = 4294967295;//MAX val allowed

int ex_i = 1234567;
string ex_s = "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven";

char nums [][6]={
				{"one"},
				{"two"},
				{"three"},
				{"four"},
				{"five"},
				{"six"},
				{"seven"},
				{"eight"},
				{"nine"},
				{"ten"},
			};
char places [][10]={
				{"hundred"},
				{"thousand"},
				{"million"},
				{"billion"},
			};
			
class Solution 
{
public:
    string numberToWords(int num) 
	{
		ostringstream o;
		o<<num;
		string nm = o.str();
		const char * numb = nm.c_str();
		int len = nm.size();
		len = len /3;
		while(len)
		{
			
		}
		return "hi";
    }
    
};

int main()
{
	Solution s;
	cout<<s.numberToWords(ex_i)<<endl;
	return 0;
 
}
