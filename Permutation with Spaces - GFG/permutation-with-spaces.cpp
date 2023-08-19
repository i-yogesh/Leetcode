//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    void recur(int i, string temp, string s, vector<string> &ans)
    {
        if(i==s.size()){
            ans.push_back(temp);
            return;
        }
        
        string op1 = temp, op2 = temp;
        op1.push_back(' ');
        op1.push_back(s[i]);
        
        recur(i+1,op1,s,ans);
        
        op2.push_back(s[i]);
        recur(i+1,op2,s,ans);
    }
    vector<string> permutation(string s){
        vector<string> ans;
        string temp="";
        temp.push_back(s[0]);
        recur(1,temp,s, ans);
        // reverse(ans.begin(),ans.end());
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