class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<matrix[0].size(); j++)
            {
                int _i=i;
                int _j=j;
                while(_i < matrix.size() && _j < matrix[0].size())
                {
                    if(matrix[i][j] != matrix[_i][_j])
                        return false;
                    _i++;
                    _j++;
                }
            }
        }
        return true;
    }
};