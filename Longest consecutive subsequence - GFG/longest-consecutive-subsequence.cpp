//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N e: size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
        unordered_set<int> st;
        int ans = 0;
        for(int i=0; i<n; i++)
            st.insert(arr[i]);
        for(int i=0; i<n; i++)
        {
            int val = arr[i];
            int count = 0;
            if(st.count(val+1))
            {
                while(st.count(val))
                {
                    count++;
                    val++;
                }
                ans = max(ans,count);
            }
        }
        return ans==0?1:ans;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends