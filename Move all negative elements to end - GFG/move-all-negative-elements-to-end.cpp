//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    void segregateElements(int arr[],int n)
    {
        vector<int> pos,neg;
        for(int i=0; i<n; i++){
            if(arr[i]<0)
                neg.push_back(arr[i]);
            else
                pos.push_back(arr[i]);
        }
        int i=0;
        for(; i<pos.size();i++){
            arr[i] = pos[i];
        }
        int j=0;
        for(; j<neg.size();){
            arr[i++] = neg[j++];
        }
    }
};

//{ Driver Code Starts.
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		ob.segregateElements(a,n);
		
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
		cout<<endl;
	}
}

// } Driver Code Ends