//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
	int LCS(string s1, string s2)
	{
	    int m=s1.size(),n=s2.size();
	    vector<vector<int>> dp(m+1, vector<int> (n+1));
	    for(int i=0; i<m+1;i++){
	        for(int j=0;j<n+1;j++){
	            if(i==0 || j==0)  
	                dp[i][j]=0;
	        }
	    }
	    for(int i=1; i<m+1;i++)
	    {
	        for(int j=1; j<n+1; j++)
	        {
	            if(s1[i-1] == s2[j-1])
	                dp[i][j] = 1+dp[i-1][j-1];
	           else
	            dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
	        }
	    }
	    return dp[m][n];
	}
	int minOperations(string str1, string str2) 
	{ 
	    int lcs = LCS(str1,str2);
	    int deleteCount  = str1.size()-lcs;
	    int insertionCoint = str2.size()-lcs;
	    int ans = deleteCount+insertionCoint;
	    return ans;
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends