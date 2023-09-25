#include<iostream>
using namespace std;
#define V 4

void addEdge(int adjMatrix[][V], int s, int d)
{
    adjMatrix[s][d]=1;
    adjMatrix[d][s]=1;    
}

void displayMatrix(int adjMatrix[][V])
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
    int adjMatrix[V][V] = {0};
    // Add edges to the graph
    addEdge(adjMatrix, 0, 1);
    addEdge(adjMatrix, 0, 2);
    addEdge(adjMatrix, 0, 3);
    addEdge(adjMatrix, 1, 2);

    // Print the adjacency matrix
    displayMatrix(adjMatrix);

    return 0;
    
}