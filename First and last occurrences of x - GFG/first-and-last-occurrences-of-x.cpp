//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int start(int* arr,int n, int x)
    {
        int s = 0, e = n-1;
        int ans1 = -1; //start
        while(s<=e)
        {
            int mid = s + (e-s)/2;
            if(arr[mid] == x){
                ans1 = mid;
                e = mid-1;
            }
            else if(arr[mid] < x){
                s=mid+1;
            }else{ //arr[mid] > x
                e = mid-1;
            }
        }
        return ans1;
    }

    int end(int* arr,int n, int x)
    {
        int s = 0, e = n-1;
        int ans2 = -1; //end
        while(s<=e)
        {
            int mid = s + (e-s)/2;
            if(arr[mid] == x){
                ans2 = mid;
                s = mid+1;
            }
            else if(arr[mid] < x){
                s=mid+1;

            }else{ //arr[mid] > x
                e = mid-1;
            }
        }
        return ans2;
    }
    vector<int> find(int arr[], int n , int x )
    {
        int ans1 = start(arr,n,x);
        int ans2 = end(arr, n,x);
        return {ans1, ans2};
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends