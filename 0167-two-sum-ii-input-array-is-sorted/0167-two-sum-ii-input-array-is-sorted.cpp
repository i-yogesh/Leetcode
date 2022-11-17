class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int s=0, e=nums.size()-1;
        while(s<e)
        {
            int sum = nums[s] + nums[e];
            if(sum == target){
                ans.push_back(s+1);
                ans.push_back(e+1);
                break;
            }
            else if(sum > target)
                e--;
            else if(sum < target)
                s++;
        }
        return ans;
    }
};