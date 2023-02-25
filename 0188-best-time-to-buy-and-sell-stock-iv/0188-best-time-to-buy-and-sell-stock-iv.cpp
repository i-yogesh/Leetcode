class Solution {
public:
     int solve(int i, bool buy, int limit, vector<int>& prices, vector<vector<vector<int>>> &dp)
    {
        if(i==prices.size())
            return 0;
        if(limit == 0)
            return 0;
        if(dp[i][buy][limit] != -1)
            return dp[i][buy][limit];

        int profit=0;
        if(buy==1)
        {
            int buyKaro = -prices[i] + solve(i+1,0,limit,prices,dp);
            int skipKaro = 0 + solve(i+1, 1, limit, prices,dp);
            profit = max(buyKaro, skipKaro);
        }
        else //buy=0
        {
            int sellKaro = prices[i] + solve(i+1, 1, limit-1, prices,dp);
            int skipKaro = 0 + solve(i+1, 0, limit, prices,dp);
            profit = max(sellKaro, skipKaro);
        }
        return dp[i][buy][limit] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        bool buy=1;
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (k+1, -1)));
        return solve(0,buy,k, prices,dp);
    }
};