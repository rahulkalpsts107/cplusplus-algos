//You have a list of packages A, B, C such that A is dependent on B,C,D and 
//B is dependent on D and C is dependent on E etc. Print the sequence of packages to run

#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>

using namespace std;
class graph 
{
	int *visited;
	int size;
	vector<int> *packageAdj;
public:
	graph(int size)
	{
		visited = new int[size];
		packageAdj = new vector<int>[size];
		this->size =size;
		int i;
		for(i =0;i<size;i++)
			visited[i]= false;
	}
	
	void addToGraph(int packageFrom , int packageTo)
	{
		packageAdj[packageFrom].push_back(packageTo);
	}
	
	void getTopoOrder(int node,stack<int> &dependencyList)
	{
		queue<int> frontier;
		frontier.push(node);
		while(!frontier.empty())
		{
			int n = frontier.front();
			cout<<"in proc "<<n<<endl;
			frontier.pop();
			if(!visited[n])
			{
				visited[n] = true;
				dependencyList.push(n);
				vector<int> &dependency = packageAdj[n];
				for(vector<int>::iterator it = dependency.begin();it != dependency.end();it++)
				{	
					frontier.push(*it);
				}
			}
			else
			{
				cout<<"visited"<<endl;
				stack<int> s1;
				while(!dependencyList.empty())
				{
					if(dependencyList.top() != n)
						s1.push(dependencyList.top());
					dependencyList.pop();
				}			
				while(!s1.empty())
				{
					dependencyList.push(s1.top());
					s1.pop();
				}
				dependencyList.push(n);	
			}
		}
	}
	
	bool getPackageDependency(stack<int> &dependencyList)
	{
		bool ret = true;
		int i;
		
		for(i=0;i<size;i++)
		{
			if(!visited[i])	
				getTopoOrder(i,dependencyList);
		}
		if(dependencyList.size() != size)
			ret = false;
		return ret;
	}
};

int main(int argc,char **argv)
{
	int size = 6;
	graph g(size);
	//g.addToGraph(0,1);
	//g.addToGraph(0,3);
	//g.addToGraph(0,2);
	//g.addToGraph(1,3);
	//g.addToGraph(1,2);
	//g.addToGraph(3,4);
	//g.addToGraph(2,4);
	g.addToGraph(5, 2);
    g.addToGraph(5, 0);
    g.addToGraph(4, 0);
    g.addToGraph(4, 1);
    g.addToGraph(2, 3);
    g.addToGraph(3, 1);
	stack<int> v;
	bool ret = g.getPackageDependency(v);
	cout<<"isFound "<<ret<<endl;
	while(!v.empty())
	{
		int n = v.top();
		cout<<n<<", ";
		v.pop();
	}
	cout<<endl;
	return 0;
} 	
