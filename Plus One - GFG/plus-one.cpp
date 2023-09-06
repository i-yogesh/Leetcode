//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int> increment(vector<int> arr ,int N) {
        int carry = 0,i=N-1;
        for(; i>=0; i--)
        {
            if(i==N-1 || carry > 0){
                int curr=0;
                if(i==N-1)
                    curr = arr[i]+1;
                else
                    curr = arr[i]+carry;
                int rem = curr%10;
                carry = curr / 10;
                arr[i] = rem;
            }
            else
                break;
        }
        if(carry>0 && i<0){
            arr.insert(arr.begin(),carry);
        }
        return arr;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        char c;
        
        cin>>N;
        vector<int> arr(N);
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> res = ob.increment(arr,N);
        for(int i: res)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends