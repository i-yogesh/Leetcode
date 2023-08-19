//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    bool isValid(string t)
    {
        if(t.size()==1)
            return true;
        if(t.size()>1 && t[0]=='0')
            return false;
        int num = stoi(t);
        if(num>255)
            return false;
        return true;
    }
    void recur(int i,int part, string temp, string &s, vector<string>& ans)
    {
        if(i==s.size() && part==4){
            ans.push_back(temp.substr(0,temp.size()-1));
            return;
        }
        else if(part==4 || i==s.size())
            return;
        recur(i+1,part+1,temp+s[i]+".",s,ans);
        
        if(s.size()>i+1 && isValid(s.substr(i,2)))
        recur(i+2,part+1,temp+s.substr(i,2)+".",s,ans);
        
        if(s.size()>i+2 && isValid(s.substr(i,3)))
        recur(i+3,part+1,temp+s.substr(i,3)+".",s,ans);
    }
    vector<string> genIp(string &s) {
        vector<string> ans;
        if(s.length()>12) return ans;
        recur(0,0,"",s,ans);
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if(str.size()==0)
            cout << -1 << "\n";
        else{
            for (auto &u : str) {
                cout << u << "\n";
            }
        }
    }
}
// } Driver Code Ends