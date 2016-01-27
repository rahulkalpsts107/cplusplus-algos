// A C++ Program to detect cycle in a graph
#include<iostream>
#include<vector>
#include <list>
#include <limits.h>

using namespace std;

class Graph
{
	int V; // No. of vertices
	list<int> *adj; // Pointer to an array containing adjacency lists
	bool isCyclicUtil(int v, bool visited[], bool *rs ,vector<int> &cycleEdges); // used by isCyclic()
public:
	Graph(int V); // Constructor
	void addEdge(int v, int w); // to add an edge to graph
	bool isCyclic(vector<int> &cycleEdges); // returns true if there is a cycle in this graph
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
}

// This function is a variation of DFSUytil() in http://www.geeksforgeeks.org/archives/18212
bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack ,vector<int> &cycleEdges)
{
	cout<<"v"<<v<<endl;
	if(visited[v] == false)
	{
		// Mark the current node as visited and part of recursion stack
		visited[v] = true;
		recStack[v] = true;

		// Recur for all the vertices adjacent to this vertex
		list<int>::iterator i;
		for(i = adj[v].begin(); i != adj[v].end(); ++i)
		{
			cout<<"adj "<<*i<<"visited "<<visited[*i]<<"recStack "<<recStack[*i]<<endl;
			if ( !visited[*i] && isCyclicUtil(*i, visited, recStack ,cycleEdges) )
			{
				cout<<"cycle detected@@ at "<<*i<<endl;
				cycleEdges.push_back(*i);
				if(cycleEdges.size() == 4)
					return true;
				return false;
			}
			else if (recStack[*i])
			{
				cout<<"cycle detected at "<<*i<<endl;
				cycleEdges.push_back(*i);
				if(cycleEdges.size() == 4)
					return true;
				return false;
			}
		}

	}
	else
	cout<<"already visited"<<endl;
	recStack[v] = false; // remove the vertex from recursion stack
	return false;
}

// Returns true if the graph contains a cycle, else false.
// This function is a variation of DFS() in http://www.geeksforgeeks.org/archives/18212
bool Graph::isCyclic(vector<int> &cycleEdges)
{
	// Mark all the vertices as not visited and not part of recursion
	// stack
	bool *visited = new bool[V];
	bool *recStack = new bool[V];
	for(int i = 0; i < V; i++)
	{
		visited[i] = false;
		recStack[i] = false;
	}

	// Call the recursive helper function to detect cycle in different
	// DFS trees
	for(int i = 0; i < V; i++)
		if (isCyclicUtil(i, visited, recStack ,cycleEdges))
			return true;

	return false;
}

int main()
{
	// Create a graph given in the above diagram
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	//g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);
	g.addEdge(3, 1);
	vector<int> cycleEdges;

	if(g.isCyclic(cycleEdges))
	{
		cout << "Graph contains cycle";
		cout<<" cycle size "<<cycleEdges.size()<<endl;
		for(vector<int>::iterator it = cycleEdges.begin(); it!=cycleEdges.end() ;it++)
			cout<<*it<<", ";
	}
	else
		cout << "Graph doesn't contain cycle";
	return 0;
}

