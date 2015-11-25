//TOPO SORT using stacks
#include<iostream>
#include<stack>
#include<vector>

using namespace std;

class graph
{
public:
	int size;
	vector<int> *adjList;
	stack<int> *topoStack;
	bool *visited;
	graph(int size)
	{
		this->size = size;	
		adjList = new vector<int>[size];
		topoStack = new stack<int>;
		visited = new bool[size];
		int i;
		for(i=0;i<size;i++)
			visited[i]=false;
	}
	
	void topoRecurse(int v)
	{
		visited[v] = true;
		for(vector<int>::iterator it = adjList[v].begin(); it < adjList[v].end() ; it++)
		{
			if(!visited[*it])
			{
				topoRecurse(*it);
			}
		}
		topoStack->push(v);
	}
	
	void addEdge(int u , int v)
	{
		adjList[u].push_back(v);
	}
	
	void topoSort()
	{
		int v = 0;
		for (;v < size ; v++)
		{
				if(!visited[v])
					topoRecurse(v);
		}
		int i = topoStack->size();
		while(i)
		{
			cout<<topoStack->top()<<", ";
			topoStack->pop();
			--i;
		}
		cout<<endl;
	}
};

int main(int argc,char **argv)
{
		int size = 6;
		graph g(6);
		g.addEdge(5, 2);
	    g.addEdge(5, 0);
	    g.addEdge(4, 0);
	    g.addEdge(4, 1);
	    g.addEdge(2, 3);
	    g.addEdge(3, 1);
		g.topoSort();
		return 0;
}
