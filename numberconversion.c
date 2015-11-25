#include <stdio.h>
#include <string>

unsigned int i = 4294967295;//MAX val allowed

int ex_i = 1234567;
string ex_s = "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven";

class Solution 
{
public:
    string numberToWords(int num) 
	{
    	int div =   4294967295/10;
		cout<<div<<endl;  
    }
};

int main()
{
	Solution s;
	cout<<s.numberToWords(ex_i)<<endl;
	return 0;
 
}
