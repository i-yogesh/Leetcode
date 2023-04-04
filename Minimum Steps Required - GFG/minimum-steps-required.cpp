//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string s) {
   int consequtiveA =0, consequtiveB = 0;
   char prev;
   for(int i=0; i<s.length(); i++){
       if(s[i] == prev)
            continue;
       if(s[i] == 'a')
            consequtiveA++;
        else if(s[i] == 'b')
            consequtiveB++;
        prev = s[i];
   }
   return min(consequtiveA, consequtiveB)+1;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends