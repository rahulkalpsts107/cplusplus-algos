//Find if the given expression contains redundant parantheses. ex :if expr = a+(b*c) , 
//print false, if expr = a+((b*c)), print true.
#include <iostream>
#include <stack>
#include <string.h>

using namespace std;
bool parseAndCheck(char *exp )
{
	stack<char> s;
	bool ret = false;
	int i =0;
	int len = strlen(exp);
	while(i < len)
	{
		cout<<"HH"<<endl;
		s.push(exp[i]);
		if(exp[i] == ')')
		{
			while(s.size() && s.top() != '(')
			{
				s.pop();
			}
			if(s.size())
			{
				s.pop();
				if(s.size() && s.top() == '(')
					ret = true;
			}
		}
		i++;
	}
	return ret;
}

int main(int argc ,char **argv)
{
	char exp[255] = "a+(e+(b*c))";
	bool ret = parseAndCheck(exp);
	cout<<ret<<endl;
	return 0;
}