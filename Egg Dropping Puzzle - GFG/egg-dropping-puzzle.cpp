//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int recur(int k,int n, vector<vector<int>> &dp)
    {
        if(n==0 || n==1)
            return n;
        if(k==1)
            return n;

        if(dp[k][n] != -1)
            return dp[k][n];

        int ans = INT_MAX;
        for(int i=1; i<=n; i++){
            int breaks = recur(k-1, i-1,dp);
            int notBreak = recur(k, n-i,dp);
            int worstCase = 1 + max(breaks,notBreak); 
            ans = min(ans,worstCase);
        }
        return dp[k][n] = ans;
    }
    int eggDrop(int n, int k) 
    {
        vector<vector<int>> dp(n+1,vector<int> (k+1,-1));
        return recur(n,k, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends