//Generate all permutation of strings memoization
#include<vector>
#include<iostream>
#include<cstring>

using namespace std;

void mixAll(vector<string> &b, char c, vector<string> &newList)
{
	for(vector<string>::iterator it = b.begin() ;it != b.end(); it++)
	{
		string &d = *it;
		//cout<<d<<" "<<d.size()<<endl;
		int len = d.size();
		int times = len+1;
		int i =0;
		while(times)
		{
			string f;
			{
				if(i !=0)
				{	
					f.append(d,0,i);
					f.append(string(1,c));
					if(i <= len -1)
						f.append(d,i,d.size());
				}
				else
				{
					f.append(string(1,c));
					f.append(d);
				}
			}
			i++;
			times--;
			cout<<f<<":"<<endl;
			newList.push_back(f);
		}
	}
}
void generateAllPerms(vector<string> *a ,int n , char c)
{
	if (n==0)
	{
		cout<<c<<":"<<endl;
		a[n].push_back(string(1,c));
	}
	else
	{
		vector<string> &b = a[n-1];
		//cout<<"next size "<<b.size()<<endl;
		mixAll(b,c,a[n]);
	}
}

int main(int argc ,char **argv)
{
	int n = 4;
	vector<string> a[4] ;
	char inp[5] = {'a' ,'b' ,'c' ,'d'};
	for(int i=0; i <n ;i++)
	{
		generateAllPerms(&a[0] ,i ,inp[i]);
	}
	return 0;
}