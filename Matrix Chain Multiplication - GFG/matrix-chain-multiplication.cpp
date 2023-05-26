//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int n, int arr[])
    {
        int ans[n][n] = {0};
        int s[n][n] = {0};
        int j,min,q;
        for(int d=1; d<n-1; d++)
        {
            for(int i=1; i<n-d; i++)
            {
                j=i+d;
                min=INT_MAX;
                for(int k=i; k<=j-1; k++)
                {
                    q = ans[i][k] + ans[k+1][j] + arr[i-1] * arr[k] * arr[j];
                    if(q < min){
                        min = q;
                        s[i][j] = k;
                    }
                }
                ans[i][j] = min;
            }
            
        }
        return ans[1][n-1];
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
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends