//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool isCycleDFS(int u, vector<int> adj[], vector<bool> &visited, int parent)
    {
        visited[u] = true;
        for(int &v: adj[u])
        {
            if(v == parent)
                continue;
            if(visited[v]) //parent bhi nhi h, visited bhi h so cycle
                return true;
            if(isCycleDFS(v,adj,visited,u))
                return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
       vector<bool> visited(V, false);
       for(int u=0; u<V; u++){ //u visited nhi h aur cycle bhi h so true
           if(!visited[u] && isCycleDFS(u, adj, visited,-1))
            return true;
       }
       return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends