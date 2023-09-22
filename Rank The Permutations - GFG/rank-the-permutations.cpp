//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    long long findRank(string s) {
        int n = s.size();
        vector<int> freq(26,0);
        for(int i=0; i<n; i++)
            freq[s[i]-'a']++;
        vector<long long> fact(n);
        fact[0]=1;
        fact[1]=1;
        long long res = 1;
        for(int i=2; i<n; i++)
            fact[i] = i*fact[i-1];
        for(int i=0; i<n; i++)
        {
            int count=0;
            for(int j=0; j<s[i]-'a';j++)
                count+= freq[j];
            freq[s[i]-'a']--;
            res+= (count*fact[n-1-i]);
        }
        return res;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        Solution obj;
        long long ans = obj.findRank(s);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends