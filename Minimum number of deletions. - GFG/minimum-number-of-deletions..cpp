//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}
// } Driver Code Ends


int minDeletions(string str, int n) { 
    
    string ss = str;
    reverse(ss.begin(), ss.end());
    vector<vector<int>> dp(n+1, vector<int> (n+1));
    for(int i=0; i<n+1; i++){
        for(int j=0; j<n+1; j++){
            if(i==0 || j==0)
                dp[i][j] = 0;
        }
    }
    
    for(int i=1; i<n+1; i++)
    {
        for(int j=1; j<n+1; j++)
        {
            if(str[i-1] == ss[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            
            else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
                
        }
    }
    int lcs = dp[n][n];
    //n is same as str.length()
    int ans = str.length() - lcs;
    return ans;
} 