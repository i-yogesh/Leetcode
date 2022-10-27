class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> ans(n-2, vector<int> (n-2));
        
        int maxi;
        for(int i=1; i<=grid.size()-2; i++)
        {
            for(int j=1; j<=grid[i].size()-2; j++)
            {
                maxi=INT_MIN;
                maxi = max({maxi, grid[i-1][j-1], grid[i-1][j], grid[i-1][j+1]});
            maxi = max({maxi, grid[i][j-1], grid[i][j], grid[i][j+1]});
                maxi=max({maxi, grid[i+1][j-1], grid[i+1][j], grid[i+1][j+1]});         
                ans[i-1][j-1]=maxi;
            }
        }
        return ans;
    }
};