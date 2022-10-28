class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& matrix) {
        int c = matrix[0].size();
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<matrix[0].size(); j++)
            {
                if(i+j == c-1 || i==j){
                    if(matrix[i][j] == 0)
                        return false;
                }
                   
                else if(matrix[i][j] > 0){
                    return false;
                }
            }
        }
        return true;
    }
};