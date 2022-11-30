class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long mini = LLONG_MAX, sum = 0, negCount=0;
        for(auto i: matrix)
        {
            for(auto j: i)
            {
                sum+= abs(j);
                if(j < 0)
                    negCount++;
                mini = mini < abs(j) ? mini : abs(j);
            }
        }
        if(negCount%2==0)
            return sum;
        //odd
        return sum-(2*mini);
    }
};