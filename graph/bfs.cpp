#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

/*
Breadth First Search (BFS) traversal of a graph.

How BFS works here:
- Start from node 0.
- Use a queue to explore nodes level by level.
- Mark nodes as visited when added to the queue (to avoid repeats).
- Pop from queue, add node to BFS traversal list.
- Then add all unvisited neighbors of that node to the queue.
- Repeat until queue is empty.
- This visits nodes in order of their shortest distance from start node.
- BFS is useful for level order traversal, shortest path in unweighted graph, etc.
*/

class Solution
{
public:
    // Function to return BFS traversal of the graph starting from node 0
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        int vis[V] = {0}; // visited array to track visited nodes
        vis[0] = 1;       // mark start node 0 as visited

        queue<int> q; // queue to manage nodes to visit next
        q.push(0);    // start BFS from node 0

        vector<int> bfs; // list to store order of BFS traversal

        // While there are nodes to process in the queue
        while (!q.empty())
        {
            int node = q.front(); // get node from front of queue (FIFO)
            q.pop();              // remove it from queue
            bfs.push_back(node);  // add node to BFS traversal list

            // Visit all neighbors of current node
            for (auto it : adj[node])
            {
                // If neighbor not visited yet
                if (!vis[it])
                {
                    vis[it] = 1; // mark neighbor visited
                    q.push(it);  // add neighbor to queue to visit next
                }
            }
        }

        return bfs; // return full BFS traversal order
    }
};

// Helper function to add edges (undirected)
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Helper function to print BFS traversal result
void printAns(vector<int> &ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}

int32_t main()
{
    fast;

    vector<int> adj[6]; // graph with 6 nodes (0 to 5)

    // Add edges (undirected)
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 4);

    Solution obj;
    vector<int> ans = obj.bfsOfGraph(5, adj); // BFS traversal starting from node 0

    printAns(ans); // print BFS traversal order

    return 0;
}
