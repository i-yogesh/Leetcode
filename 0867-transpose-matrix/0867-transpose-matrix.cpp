class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n=matrix[0].size();
        vector<vector<int>> ans(n, vector<int>(matrix.size())) ;
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<n;j++)
            {
                // swap(matrix[i][j], matrix[j][i]);
                ans[j][i] = matrix[i][j];
            }
        }
        return ans;
    }
};