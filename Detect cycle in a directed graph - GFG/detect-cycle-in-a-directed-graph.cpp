//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool checkCycleDirected(int u, vector<int> adj[], vector<bool> &visited, vector<bool> &inCurrRecursion)
    {
        if(visited[u])
            return true;
        visited[u] = true;
        inCurrRecursion[u] = true;
        
        for(int &v: adj[u]){
            
            if(visited[v] && inCurrRecursion[v])
                return true;
                
            if(!visited[v]){
                if(checkCycleDirected(v, adj, visited, inCurrRecursion))
                    return true;
            }
            
        }
        inCurrRecursion[u]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        vector<bool> inCurrRecursion(V, false);
        
        for(int u=0; u<V; u++){
            if(!visited[u] && checkCycleDirected(u, adj, visited, inCurrRecursion))
                return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends