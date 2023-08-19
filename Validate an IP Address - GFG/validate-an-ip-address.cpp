//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
        int isValid(string s) {
            int dot=0;
            if(s[0]=='.'||s[s.length()-1]=='.') return 0;
            for(int i=0;i<s.length()-1;i++){
                if(s[i]=='.' && s[i+1]=='.')
                    return 0;
                if((s[i]>='0' && s[i]<='9') || (s[i]=='.'))
                    continue;
                else
                    return 0;
            }
            stringstream  complt(s);
            string segment;
            vector<string> segList;
            while(getline(complt,segment,'.'))
                segList.push_back(segment);
            if(segList.size()!=4) return 0;
            for(auto &i: segList){
                string ss = i;
                if(ss.length()>=4) return 0;
                if(ss.length()>1 && ss[0]=='0') return 0;
                int num=0;
                for(auto j: ss){
                    num = (num*10)+j-'0';
                }
                
                if(num<0 ||num>255)
                    return 0;
            }
            return 1;
        }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}
// } Driver Code Ends