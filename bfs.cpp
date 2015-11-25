//Bread first search using queue
//TOPO SORT using stacks
#include<iostream>
#include<list>
#include<vector>

using namespace std;

class graph
{
public:
	int size;
	vector<int> *adjList;
	bool *visited;
	graph(int size)
	{
		this->size = size;	
		adjList = new vector<int>[size];
		visited = new bool[size];
		int i;
		for(i=0;i<size;i++)
			visited[i]=false;
	}
	
	void bfs(int v)
	{
		visited[v] = true;
		list<int> *q = new list<int>;
		q->push_front(v);
		
		while(!q->empty())
		{
			v = q->front();
			cout<<v<<" ";
			q->pop_front();
			for(list<int>::iterator it = q->begin() ; it != q->end();it++)
			{
				if(!visited[*it])	
				{
					visited[*it] = true;			
					q->push_front(*it);
				}
			}
		}
	}
		
	void addEdge(int u , int v)
	{
		adjList[u].push_back(v);
	}
	
};

int main(int argc,char **argv)
{
		int size = 6;
		graph g(6);
		g.addEdge(2, 3);
	    g.addEdge(3, 1);
	    g.addEdge(4, 1);
	    g.addEdge(4, 0);
	    g.addEdge(5, 2);
	    g.addEdge(5, 0);
	    int v;
	    for(v=0;v<size;v++)
	    {
	    	if(!g.visited[v])
				g.bfs(v);
		}
		return 0;
}
