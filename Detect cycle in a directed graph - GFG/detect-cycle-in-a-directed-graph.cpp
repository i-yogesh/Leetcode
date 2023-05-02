//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool isCyclic(int V, vector<int> adj[]) {
        //1.Fill Indegree Array
	    vector<int> indegree(V, 0);
	    for(int u=0; u<V; u++){
	        for(int &v: adj[u]){
	            indegree[v]++;
	        }
	    }
	    
	    
	    queue<int> q;
	    //2. Fill queue with indegree 0
	    for(int u=0; u<V; u++){
	        if(indegree[u]==0)
	            q.push(u);
	    }
	    
	    int nodeCount=0; //Important
	    
	    //3.Simple BFS
	    while(!q.empty()){
	        int node = q.front();
	        nodeCount++;
	        q.pop();
	        
	        //Decrease indegree for the node getting visited and if its 0 pushinto the queue
	        for(int& v: adj[node]){
	           indegree[v]--;
	            if(indegree[v] == 0)
	                q.push(v);
	        }
	    }
	    if(nodeCount!=V) //agr queue puri nhi bhr rhi mtlb cycle h
	        return true;
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