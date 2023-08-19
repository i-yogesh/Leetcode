//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    void recur(string s,string temp, vector<string> &ans)
    {
        if(s.empty()){
            ans.push_back(temp);
            return;
        }
        string op1 = temp, op2= temp;
        
        op1.push_back(' ');
        op1.push_back(s[0]);
        
        op2.push_back(s[0]);
        s.erase(s.begin()+0);
        
        recur(s,op1,ans);
        recur(s,op2,ans);
    }
    vector<string> permutation(string s){
        string temp="";
        temp.push_back(s[0]);
        s.erase(s.begin()+0);
        vector<string> ans;
        recur(s,temp,ans);
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