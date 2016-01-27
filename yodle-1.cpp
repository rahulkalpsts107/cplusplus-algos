//Write a program in a language of your choice to find the maximum total from top to bottom in triangle.txt, a text file containing a //triangle with 100 rows. 
//txt
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void retCurMax(vector<vector<int> > &matrix ,int idx)
{
	if(idx == matrix.size()-1)
		return ;
	else
	{
		retCurMax(matrix,idx+1);//recurse
		vector<int> &curr = matrix[idx]; //curr
		vector<int> &next = matrix[idx+1]; //bottom
		for(int i= 0; i< curr.size() ;i++)
		{
			curr[i]= curr[i]+max(next[i] ,next[i+1]); //append to existing matrix
		}
	}
}

int main(int argc ,char **argv)
{
	ifstream ifs("triangle.txt");
	if(ifs)
	{
		string cur;
		vector<vector<int> > matrix;
		while(getline(ifs,cur))
		{
			vector<int> line;
			int c;
		  	std::stringstream iss(cur);
		  	while ( iss >> c) 
		  	{    
		    	line.push_back(c);
		  	}
			matrix.push_back(line);
		}
		retCurMax(matrix,0);
		cout<<matrix[0][0]<<endl;
	}
	else
		cout<<"error no file"<<endl;
	return 0;
}