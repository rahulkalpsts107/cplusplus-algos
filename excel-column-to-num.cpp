#include<iostream>
#include<string.h>
#include<cmath>

using namespace std;
int main(int argc,char **argv)
{
	if(argc == 2)	
	{
		char * str = argv[1];
		int idx = strlen(str);
		int sum =0;
		idx-=1;
		double ret = 0;
		double power = 0;
		double ans = 0;
		cout<<"Inp - "<<str<<endl;
		while(idx>=0)
		{
			if(str[idx] >= 'A' && str[idx]<='Z')
			{
				double val = str[idx] - 'A' +1;
				ans+= std::pow(26,power)*val;
				power++;
			}
			else
			{
				ret =1;
				break;
			}
			--idx;
		}
		if(ret !=0)
			cout<<"errr input"<<endl;
		else
			cout<<"col num - "<<ans<<endl;
	}
	else
	{
		cout<<"error : wrong input"<<endl;
	}
}
