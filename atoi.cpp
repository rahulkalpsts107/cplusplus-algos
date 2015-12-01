//Implement atoi to convert a string to an integer.
#include<string>
#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;

class Solution {
public:
	bool isDigit(char c)
	{
		bool ret = false;
		if	((c >= 48 && c <=57))
			ret = true;
		return ret;
	}
	
	int retActualLength(const char * str)
	{
		int count =0;
		int i=0;
		while(str[i] != '\0')
		{
			if((str[i] != ' ') && (str[i] != '-' && (str[i] != '+'))) count ++;
			i++;
		}
		return count;
	}
	
    int myAtoi(string str) {
        const char * str1 = str.c_str();
        int i =0;
        int ret = 0;
        int digs = retActualLength(str1);
        int mul = pow(10,digs>0?digs-1:0);
        int sign = -1;
        while(str1[i] != '\0')
        {
        	cout<<mul<<endl;
        	if(str1[i] == ' ')//omit whitespace
			{
				i++;
				continue;
			}
			else if(str1[i] == '-')
			{
				if(ret>0)
					break;
				else
				{
					if(sign == -1)
						sign = 1;
					else
						break;
				}
			}
			else if(str1[i] == '+')
			{
				if(ret>0)
					break;
				else
				{
					if(sign == -1)
						sign = 0;
					else
						break;
				}
			}
        	else if(isDigit(str[i]))
			{
				int val = str1[i] - 48;
				ret+=(val*mul);
				mul/=10;
			}
			else 
			{
				ret = 0;
				break;
			}
        	i++;
		}
		if(sign == 1)
			ret *=-1;
		return ret;
    }
};

int main(int argc ,char **argv)
{
	Solution s;
	string s1 = (" -1 23 89");
	cout<<s.myAtoi(s1)<<endl;
	return 0;
}
