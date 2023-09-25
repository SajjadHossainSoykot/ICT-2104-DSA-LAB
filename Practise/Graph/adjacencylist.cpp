#include <iostream>
using namespace std;
#define V 4

void addEdge(int adjMatrix[][V], int s, int d)
{
    adjMatrix[s][d] = 1;
    adjMatrix[d][s] = 1;
}

void displayList(int adjMatrix[][V])
{
    cout << "Adjacency List:\n";
    for (int i = 0; i < V; i++)
    {
        cout << "Vertex " << i << " :";
        for (int j = 0; j < V; j++)
        {
            if (adjMatrix[i][j] != 0)
                cout << " -> " << j;
        }
        cout << endl;
    }
}

int main()
{
    int adjMatrix[V][V] = {0};

    addEdge(adjMatrix, 0, 1);
    addEdge(adjMatrix, 0, 2);
    addEdge(adjMatrix, 0, 3);
    addEdge(adjMatrix, 1, 2);

    displayList(adjMatrix);

    return 0;
}