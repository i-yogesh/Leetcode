//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    string lookandsay(int n) {
        if (n == 1) 
            return "1";
        string last = "1";
        string temp="",ans=last;
        while(n>1){
            temp="";
            string currS = last;
            for(int j=0; j<currS.size(); j++){
                int num = currS[j]-'0', c=0;
                
                while(j+1<currS.size() && currS[j] == currS[j+1]){
                    j++; c++;
                }
                // c++;
                temp+= to_string(c+1) +to_string(num);
                // c=1;
            }
            last = temp;
            ans = temp;
            n-=1;
        }
        return ans;
    }   
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution obj;
        cout<<obj.lookandsay(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends