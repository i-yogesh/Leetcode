//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    const int mod = 1000000007;
    long long recur(int n, vector<int> &dp)
    {
        if(n==0)
            return 1;
        if(n<0) 
            return 0;
        if(dp[n] != -1)
            return dp[n];
            
        long long ans1 = recur(n-1,dp) + recur(n-2,dp) + recur(n-3,dp);
        return dp[n] = ans1%mod;
    }
    long long countWays(int n)
    {
        vector<int> dp(n+1,-1);
        return recur(n,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends