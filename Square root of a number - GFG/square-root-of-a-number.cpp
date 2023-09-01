//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        if(x==1) return 1;
        long long int s = 0, e = x,ans=1;
        while(s<=e)
        {
            long long int mid = s+(e-s)/2;
            if(mid*mid == x)
                return mid;
            long long int curr = mid*mid;
            if(curr < x)
                s=mid+1;
            else
                e = mid-1;
        }
        return e;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends