#include <iostream>
using namespace std;
#define V 4
// Function to add an edge to the adjacency matrix
void addEdge(int adjMatrix[][V], int source, int destination)
{
    adjMatrix[source][destination] = 1;
    adjMatrix[destination][source] = 1; // For an undirected graph
}

// Function to print the adjacency matrix
void printMatrix(int adjMatrix[][V])
{
    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < V; i++)
    {   cout<<i<<": ";
        for (int j = 0; j < V; j++)
        {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int adjMatrix[V][V] = {0}; // Initialize the adjacency matrix with zeros

    // Add edges to the graph
    addEdge(adjMatrix, 0, 1);
    addEdge(adjMatrix, 0, 2);
    addEdge(adjMatrix, 0, 3);
    addEdge(adjMatrix, 1, 2);

    // Print the adjacency matrix
    printMatrix(adjMatrix);

    return 0;
}
/* Output:

Adjacency Matrix:
0: 0 1 1 1
1: 1 0 1 0
2: 1 1 0 0
3: 1 0 0 0

*/