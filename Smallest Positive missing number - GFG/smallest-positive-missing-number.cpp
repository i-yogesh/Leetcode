//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        int maxi=0;
        unordered_set<int> st;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0; i<n; i++){
            if(arr[i] > 0){
                if(!st.count(arr[i]))
                pq.push(arr[i]);
                st.insert(arr[i]);
                maxi = max(maxi, arr[i]);
            }
        }
        if(pq.empty()) return 1;
        int c=1;
        while(!pq.empty()){
            if(c!=pq.top())
                return c;
            c++;
            pq.pop();
        }
        return maxi+1;
    } 
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends