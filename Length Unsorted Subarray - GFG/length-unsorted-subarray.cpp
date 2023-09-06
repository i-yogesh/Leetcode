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
	    sort(temp.begin()+s, temp.begin()+e+1);
	    int mini = temp[e],ansE=e;
	    for(i=e; i<n; i++){
	        if(temp[i]<temp[e]){
	           // mini = min(mini, temp[i]);
	            ansE=i;
	        }
	    }
	    //start
	    int maxi = temp[s],ansS=s;
	    for(i=s; i>=0; i--){
	        if(temp[i]>temp[s]){
	           // maxi = max(maxi, temp[i]);
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