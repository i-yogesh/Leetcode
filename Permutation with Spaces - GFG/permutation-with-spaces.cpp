//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    void recur(int i,string s, vector<string> &ans)
    {
        if(i>=s.size()){
            ans.push_back(s);
            return;
        }
        recur(i+1,s,ans);
        s.insert(s.begin()+i, ' ');
        recur(i+2,s,ans);
    }
    vector<string> permutation(string s){
        vector<string> ans;
        recur(1,s, ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}

// } Driver Code Ends