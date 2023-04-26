//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    void DFS(int u, unordered_map<int, vector<int>>& adj, vector<bool> &visited, vector<int> &res)
    {
        if(visited[u] == true)
            return;
        
        visited[u]=true;
        res.push_back(u);
        for(auto &v: adj[u]){
            if(!visited[v])//not visited
                DFS(v,adj,visited,res);
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> mp[]) {
       unordered_map<int, vector<int>> adj;
       for(int u=0; u<V; u++)
       {
           for(auto &v: mp[u]){
               adj[u].push_back(v);
           }
       }
       vector<int> res;
       vector<bool> visited(V, false);
       DFS(0,adj,visited,res);
       return res;
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends