/*
1)	Create a Graph G = (V, E), directed, weighted by your self  
2)	Define a structure to represent this graph  
3)	Implement one algorithm of graph traversal.  
4)	Run and report the result with the graph created in (1) 
*/
// C++ program to print DFS traversal from
// a given vertex in a  given graph
#include <bits/stdc++.h>
using namespace std;


struct Graph 
{
   map<int, bool> visited;
   map<int, list<int> > adj;

   // function to add an edge to graph
   void addEdge(int v, int w);

   // DFS traversal of the vertices
   // reachable from v
   void DFS(int v);

   void printGraph();
};

void Graph::addEdge(int v, int w)
{
   adj[v].push_back(w); // Add w to v’s list.
}

void Graph::DFS(int v)
{
   // Mark the current node as visited and
   // print it
   visited[v] = true;
   cout << v << " ";

   // Recur for all the vertices adjacent
   // to this vertex
   list<int>::iterator i;
   for (i = adj[v].begin(); i != adj[v].end(); ++i)
      if (!visited[*i])
         DFS(*i);
}

void Graph::printGraph()
{
   cout << "Printing nodes' infor of the graph" << endl;
   for (auto map_it = adj.begin(); map_it != adj.end(); map_it++)
   {
      cout << map_it->first << " => " ;
      auto subset = map_it->second;
      for (auto list_it = subset.begin(); list_it != subset.end(); list_it++)  
      {
         cout << *list_it << " " ;
      }
      cout << "\n";
   }
}

int main()
{
   // Create a graph given in the above diagram
   Graph g;
   g.addEdge(0, 1);
   g.addEdge(0, 2);
   g.addEdge(1, 2);
   g.addEdge(2, 0);
   g.addEdge(2, 3);
   g.addEdge(3, 3);

   g.printGraph();

   cout << "Following is Depth First Traversal"
         " (starting from vertex 2) \n";
   g.DFS(2);

   return 0;
}