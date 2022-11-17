class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]] = i+1;
        }
        vector<int> ans;
        
        for(int i=0; i<nums.size(); i++)
        {
            int num = nums[i];
            if(mp.find(target-num)!=mp.end()){
                auto it = mp.find(target-num);
                ans.push_back(i+1);
                ans.push_back(it->second);
                break;
            }
        }
        return ans;
    }
};