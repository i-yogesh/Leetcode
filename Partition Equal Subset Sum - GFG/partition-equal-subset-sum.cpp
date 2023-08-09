//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool recur(int i, int target, int N, int *arr, vector<vector<int>> &dp)
    {
        if(i==N)
            return target == 0 ? 1 : 0;
        
        if(target == 0)
            return 1;
        if(dp[i][target]!=-1)
            return dp[i][target];
            
        bool pick = recur(i+1,target-arr[i], N, arr,dp);
        bool nPick = recur(i+1, target, N, arr,dp);
        
        return dp[i][target] = (pick || nPick);
    }
    int equalPartition(int N, int arr[])
    {
        int target  = 0;
        for(int i=0; i<N; i++){
            target+= arr[i];
        }
        if(target%2!=0)
            return 0;//odd
            
        target/=2;
        vector<vector<int>> dp(N+1, vector<int> (target+1,-1));
        return recur(0,target,N,arr,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends