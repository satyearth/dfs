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
/*
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Network
{
    int n;                   // Number of systems
    vector<vector<int>> adj; // Adjacency list

public:
    Network(int numSystems) : n(numSystems)
    {
        adj.resize(n); // Initialize adjacency list for n systems
    }

    // Function to add an edge between systems
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        // For undirected graph, add the line below to make it bidirectional
        // adj[v].push_back(u);
    }

    // Depth-First Search traversal to find reachable systems
    void DFS(int start, vector<bool> &visited)
    {
        visited[start] = true; // Mark the current system as visited
        cout << start << " ";  // Output the current system (reachable)

        // Traverse all systems adjacent to the current system
        for (int u : adj[start])
        {
            if (!visited[u])
            {
                DFS(u, visited); // Recursive DFS call for unvisited systems
            }
        }
    }

    // Function to find reachable systems from a given system
    void findReachableSystems(int start)
    {
        vector<bool> visited(n, false); // Array to mark visited systems

        cout << "Systems reachable from system " << start << ": ";
        DFS(start, visited);
        cout << endl;
    }
};

int main()
{
    int numSystems = 6; // Number of systems in the network
    Network network(numSystems);

    // Adding edges between systems
    network.addEdge(0, 1);
    network.addEdge(0, 2);
    network.addEdge(1, 3);
    network.addEdge(1, 4);
    network.addEdge(2, 4);
    network.addEdge(3, 5);
    network.addEdge(4, 5);

    int startSystem = 0; // Choose the starting system for DFS traversal
    clock_t start,end;
    start=clock();
    network.findReachableSystems(startSystem);
    end=clock();
    double time_spent = (double)(end-start)/CLOCKS_PER_SEC;
    cout<<"\ntime spent: "<<time_spent;

    return 0;
}
*/
