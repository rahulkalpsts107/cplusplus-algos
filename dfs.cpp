#include <iostream>
#include <vector>

//detect cycle for undirected graph
using namespace std ;
class graph
{
	public:
		vector<int> *adjList;
		bool *visited;
		int size ;
		graph(int size)
		{
			adjList = new vector<int>[size];
			visited = new bool[size];
			this->size = size;
			int i = 0;
			for(;i<size;i++)
				visited[i]=false;
		}
		
		void addEdge(int u ,int v)
		{
			adjList[u].push_back(v);
			adjList[v].push_back(u);
		}
		
		int dfs_visit(int n,int parent)
		{
			vector<int> &edges = adjList[n];
			int i =0;
			bool ret =false;
			visited[n] =true;
			for(;i<edges.size();i++)
			{
				if(!visited[edges[i]])
				{
					ret = dfs_visit(edges[i],n);
					if (ret == true) break;
				}
				else
				{
					if(visited[edges[i]])
						if(edges[i] != parent) 
						{
							ret = true;
							break;
						}
				}
			}
			return ret;
		}
		
		bool isCycle()
		{
			int i =0;
			bool ret = false;
				
			for(;i<size;i++)
			{
				vector<int> &edges = adjList[i];
				int j=0;
				if(!visited[i])
					if(dfs_visit(i,-1) == true)
					{
						cout<<"cycle exists !"<<endl;
						ret = true;
						break;
					}
			}
			return ret;
		}
};

int main(int argc,char **argv)
{
	int size = 5;
	graph g(size);
	bool ret = false;
	g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 0);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
	ret = g.isCycle();
	cout<<ret<<endl;
	graph g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    ret = g2.isCycle();
    cout<<ret<<endl;
	return 0;
}

