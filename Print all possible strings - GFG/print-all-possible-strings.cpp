//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

vector<string>  spaceString(char str[]);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        char str[10000];
        cin>>str;
        vector<string> vec = spaceString(str);
        for(string s: vec){
            cout<<s<<"$";
        }
        cout<<endl;
    }

}

// } Driver Code Ends


/*You have to complete this function*/

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
vector<string>  spaceString(char str[])
{
    string s(str);
    vector<string> ans;
    recur(1,s, ans);
    return ans;
}