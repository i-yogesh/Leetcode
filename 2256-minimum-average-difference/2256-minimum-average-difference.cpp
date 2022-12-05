class Solution
{
    public:
        int minimumAverageDifference(vector<int> &nums)
        {
            if (nums.size() == 1 && nums[0] == 0) return 0;
            long long sum = 0, currSum = 0, lastSum = 0, n = nums.size(), mini = INT_MAX, idx = 0;
            for (int i = 0; i < nums.size(); i++)
                sum += nums[i];

            for (int i = 0; i < nums.size() - 1; i++)
            {
                currSum += nums[i];
               	// cout<<currSum<<endl;
                int currAvg = currSum / (i + 1);

                lastSum = sum - currSum;
               	// cout<<lastSum<<endl;
                int lastAvg = lastSum / (n - i - 1);

                int diff = abs(currAvg - lastAvg);
                cout << diff << endl;
                if (diff < mini)
                {
                    mini = diff;
                    idx = i;
                }
            }
            long long diff = sum / n;
            if (diff < mini){
                mini = diff;
                idx = n-1;
            }
            // cout<<diff;
            return idx;
        }
};