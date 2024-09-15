#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void addEdge(vector<vector<int>> &graph, int u, int v)
{
    graph[u][v] = 1;
    graph[v][u] = 1;
}
void DFS(vector<vector<int>> &graph, int startNode)
{
    int numNodes = graph.size();
    vector<bool> visited(numNodes, false);
    stack<int> stk;

    stk.push(startNode);

    while (!stk.empty())
    {
        int currentNode = stk.top();
        stk.pop();
        if (!visited[currentNode])
        {
            cout << currentNode << " ";
            visited[currentNode] = true;
            for (int i = numNodes - 1; i >= 0; --i)
            {
                if (graph[currentNode][i] && !visited[i])
                {
                    stk.push(i);
                }
            }
        }
    }
}
int main()
{
    int numNodes = 5;

    vector<vector<int>> graph(numNodes, vector<int>(numNodes, 0));

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);

    int startNode;
    cout << "Enter the starting node for DFS traversal: ";
    cin >> startNode;

    cout << "DFS Traversal starting from node " << startNode << ": ";
    DFS(graph, startNode);
    return 0;
}
