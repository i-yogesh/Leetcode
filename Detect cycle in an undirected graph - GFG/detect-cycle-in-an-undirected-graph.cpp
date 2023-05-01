//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool checkCycleBFS(int u, vector<int> adj[], vector<bool> &visited){
        
        queue<pair<int,int>> q;
        visited[u] = true;
        q.push({u,-1});
        
        while(!q.empty())
        {
            int node = q.front().first; 
            int parent = q.front().second;
            q.pop();
            
            for(int &v: adj[node]){
                if(parent == v)
                    continue;
                if(visited[v]) //parent bhi nhi h, visited bhi h
                    return true;
                visited[v] = true;
                q.push({v, node});
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        
        for(int u=0; u<V; u++){
            if(!visited[u] && checkCycleBFS(u,adj,visited))
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