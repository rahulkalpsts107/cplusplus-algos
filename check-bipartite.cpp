//Check bipartiteness in directed graph- use BFS
#include<iostream>
#include<vector>
#include<list>

using namespace std;
class graph
{
public:
	vector<int>	*adjList;
	int size;
	bool *visited;
	int *color;
	graph(int size)
	{
		this->size = size;
		adjList = new vector<int>[size];
		visited = new bool[size];
		int i = size;
		while(i)
			visited[i--]=false;
		color = new int[size];
	}
	
	void addEdge(int u,int v)
	{
		adjList[u].push_back(v);
	}
	
	bool bfsVisit(int parent)
	{
		bool ret = false;
		list<int> q;
		q.push_front(parent);
		
		while(!q.empty())
		{
			int adj = q.front();
			q.pop_front();
			for(vector<int>::iterator it = adjList[adj].begin();it != adjList[adj].end();it++)
			{
				if(!visited[*it])
				{
					if(color[adj] == 1)
						color[*it] = 0;
					else
						color[*it] = 1;
				}
				else
				{
					if(color[adj]==color[*it])
					{
						ret = true;
						break;
					}
				}
				q.push_front(*it);
			}
		}
	}
	
	bool isBipartite()
	{
		int v ;
		bool ret = false;
		for	(v=0;v<size;v++)
		{
			color[v] = 1;//by default white
			if (bfsVisit(v) == true)
			{
				ret = true;
				break;
			}
		}
		return ret;
	}
};

int main(int argc , char **argv)
{
	graph g(6);
	g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.addEdge(4, 1);
    g.addEdge(4, 0);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    if(g.isBipartite()) cout<<"is bipartite"<<endl;
    else cout<<"not bipartite"<<endl;
	return 0;
}
