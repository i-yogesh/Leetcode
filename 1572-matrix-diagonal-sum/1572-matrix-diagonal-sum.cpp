class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum=0;
        for(int i=0; i<mat.size(); i++)
        {
            for(int j=0; j<mat[0].size(); j++)
            {
                if(i==j)
                    sum+=mat[i][j];
                if(i+j == mat[i].size()-1 && i!=j)
                    sum+=mat[i][j];
            }
        }
        return sum;
    }
};