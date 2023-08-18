//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        unordered_map<char,int> mp, mp2;
        for(auto &i:a)
            mp[i]++;
        for(auto &i:b)
            mp2[i]++;
        for(auto &i: mp){
            if(mp2.find(i.first)==mp2.end())
                return false;
            if(i.second != mp2[i.first])
                return false;
        }
        for(auto &i: mp2){
            if(mp.find(i.first)==mp.end())
                return false;
            if(i.second != mp[i.first])
                return false;
        }
        return true;
    }

};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends