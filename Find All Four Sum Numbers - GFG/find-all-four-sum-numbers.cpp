//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        if(nums.size() < 4)
            return ans;
        sort(nums.begin(), nums.end());
        for(int i=0 ; i<nums.size()-3; i++)
        {
            if(i>0 && nums[i] == nums[i-1])
                continue;
            for(int j=i+1; j<nums.size()-2; j++)
            {
                if(j>i+1 && nums[j] == nums[j-1])
                continue;
                
                int l=j+1;
                int h = nums.size()-1;
                long long s = target - nums[i] - nums[j];
                while(l<h)
                {
                    if(s == nums[l] + nums[h])
                    {
                        ans.push_back({nums[i], nums[j], nums[l], nums[h]});
                        while(l <h && nums[l] == nums[l+1])
                            l++;
                        while(l<h && nums[h] == nums[h-1])
                            h--;
                        l++;
                        h--;
                    }
                        
                    else if(nums[l] + nums[h] < s)
                        l++;
                    else
                        h--;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends