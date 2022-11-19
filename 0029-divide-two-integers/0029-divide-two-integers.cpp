class Solution {
public:
    int divide(int dividend, int divisor) {
        long long ans = (long long)dividend/divisor;
        if(ans < INT_MIN)
            return INT_MIN;
        if(ans > INT_MAX)
            return INT_MAX;
        return ans;
    }
};