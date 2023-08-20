//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    bool recur(int m,int n, int len, string A, string B, string C, int dp[101][101][201])
    {
        if(len==0)
            return 1;
        if(dp[m][n][len]!=-1)
            return dp[m][n][len];
            
        bool ch1=0,ch2=0;
        if(m-1>=0 && A[m-1]==C[len-1])
            ch1 = recur(m-1,n,len-1,A,B,C,dp);
        if(n-1>=0 && B[n-1]==C[len-1])
            ch2 = recur(m,n-1,len-1,A,B,C,dp);
        return dp[m][n][len] = ch1 || ch2;
    }
    bool isInterleave(string A, string B, string C) 
    {
         int m=A.length(),n=B.length(),len=C.length();
         int dp[101][101][201];
         memset(dp,-1,sizeof(dp));
         return recur(m,n,len,A,B,C,dp);
    }

};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}
// } Driver Code Ends