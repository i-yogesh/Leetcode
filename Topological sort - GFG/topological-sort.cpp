//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order.
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    //1.Fill Indegree Array
	    vector<int> indegree(V, 0);
	    for(int u=0; u<V; u++){
	        for(int &v: adj[u]){
	            indegree[v]++;
	        }
	    }
	    
	    vector<int> ans;
	    queue<int> q;
	    //2. Fill queue with indegree 0
	    for(int u=0; u<V; u++){
	        if(indegree[u]==0)
	            q.push(u);
	    }
	    
	    //3.Simple BFS
	    while(!q.empty()){
	        int node = q.front();
	        ans.push_back(node);
	        q.pop();
	        
	        //Decrease indegree for the node getting visited and if its 0 pushinto the queue
	        for(int& v: adj[node]){
	           indegree[v]--;
	            if(indegree[v] == 0)
	                q.push(v);
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends