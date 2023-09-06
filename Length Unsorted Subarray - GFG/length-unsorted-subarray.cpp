//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> printUnsorted(int arr[], int n) {
	    vector<int> temp(arr,arr+n);
	    int i=0,s=0,e=n-1;
	    for(; i<n+1; i++){
	        if(temp[i]>temp[i+1]){
	            s=i;
	            break;
	        }
	    }
	    i=n-1;
	    for(; i>=0; i--){
	        if(temp[i] < temp[i-1]){
	            e=i;
	            break;
	        }
	    }
	    int mini = INT_MAX,maxi=INT_MIN;
	    for(int j=s; j<=e; j++){
	        mini = min(mini, temp[j]);
	        maxi = max(maxi,temp[j]);
	    }
	    int ansE=e;
	    for(i=e; i<n; i++){
	        if(temp[i]<maxi){
	            ansE=i;
	        }
	    }
	    //start
	    int ansS=s;
	    for(i=s; i>=0; i--){
	        if(temp[i]>mini){
	            ansS=i;
	        }
	    }
	    return {ansS,ansE};
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printUnsorted(arr, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}

// } Driver Code Ends