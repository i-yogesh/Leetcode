//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
  public:
    int minDist(int a[], int n, int x, int y) {
        if(x==y) return -1;
       int mini = INT_MAX;
       vector<int> xvr, yvr;
       for(int i=0; i<n; i++){
           if(a[i]==x)
                xvr.push_back(i);
           else if(a[i] == y)
                yvr.push_back(i);
       }
    //   if(xvr.empty() && !yvr.empty()) return false;
    //   if(!xvr.empty() && yvr.empty()) return false;
       for(int i=0; i<xvr.size(); i++){
           for(int j=0; j<yvr.size(); j++){
               mini = min(mini, abs(xvr[i]-yvr[j]));
           }
       }
       if(mini == INT_MAX )return -1;
       return mini;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}

// } Driver Code Ends