//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    
    void BFS(int u, unordered_map<int, vector<int>>& adj, vector<bool> &visited, vector<int> &res)
    {
        queue<int> q;
        
        q.push(u);
        visited[u]=true;
        res.push_back(u);
        
        while(!q.empty())
        {
            int currU = q.front();
            q.pop();
            
            for(int& v: adj[currU]){
                if(!visited[v]){
                    visited[v] = true;
                    q.push(v);
                    res.push_back(v);
                }
            }
        }
    }
    vector<int> bfsOfGraph(int V, vector<int> mp[]) {
        unordered_map<int, vector<int>> adj;
        for(int u=0; u<V; u++){
            for(int &v: mp[u]){
                adj[u].push_back(v);
            }
        }
        vector<bool> visited(V, false);
        vector<int> res;
        BFS(0,adj,visited,res);
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends