#include <iostream>
#include <vector>
using namespace std;
// Add edge
void addEdge(vector<int> vertex[], int source, int destination)
{
    vertex[source].push_back(destination);
    vertex[destination].push_back(source);
}
// Print the vertex
void printGraph(vector<int> vertex[], int V)
{
    for (int d = 0; d < V; d++)
    {
        cout << "Vertex " << d << ":";
        for (int i = 0; i < vertex[d].size(); i++)
        {
            cout << "-> " << vertex[d].at(i);
        }
        cout << endl;
    }
}
int main()
{
    // Total Vertices
    int V = 4;
    // Create a vertex with vector
    vector<int> vertex[V];
    // Add edges
    addEdge(vertex, 0, 1);
    addEdge(vertex, 0, 2);
    addEdge(vertex, 0, 3);
    addEdge(vertex, 1, 2);
    printGraph(vertex, V);
    return 0;
}
/* Output:

Vertex 0:-> 1-> 2-> 3
Vertex 1:-> 0-> 2    
Vertex 2:-> 0-> 1    
Vertex 3:-> 0

*/