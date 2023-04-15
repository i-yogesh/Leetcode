//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
     string isPalindrome(int i, int j, string& s)
    {
        int storeI = i,storeJ=j;
        while(i<j){
            if(s[i] != s[j])
                return "";
            i++;
            j--;
        }
        string res = s.substr(storeI, storeJ-storeI+1);
        return res;
    }
    string longestPalindrome(string s){
        string maxi="";
        for(int i=0; i<s.size(); i++)
        {
            for(int j=i; j<s.size(); j++)
            {
                    
                    string res = isPalindrome(i,j,s);
                    if(res.size() > maxi.size())
                        maxi = res;
            }
        }
        return maxi;
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends