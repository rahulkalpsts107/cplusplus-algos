#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main(int argc ,char **argv)
{
	ifstream ifs("triangle.txt");
	if(ifs)
	{
		int c;
		vector<int> cl;
	  	std::string line;
	  	while(getline(ifs, line))
	  	{
		  	std::stringstream iss(line);
		  	while ( iss >> c) 
		  	{    
		  		cout<<c<<" ";
		    	cl.push_back(c);
		  	}
		  	cout<<endl;
		}
	}
}