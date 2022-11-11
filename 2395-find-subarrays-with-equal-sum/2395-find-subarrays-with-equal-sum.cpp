class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i=1; i<nums.size(); i++)
        {
            mp[nums[i] + nums[i-1]]++;
            if(mp[nums[i] + nums[i-1]] > 1)
                return true;
        }
        return false;
    }
};