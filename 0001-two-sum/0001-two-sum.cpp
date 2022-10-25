class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]=i;
        }
        vector<int> ans;
        for(int i=0; i<nums.size(); i++)
        {
            int number=nums[i];
            if(mp.find(target-number) != mp.end()){
                if(mp[target-number] == i)
                    continue;
                ans.push_back(i);
                ans.push_back(mp[target-number]);
                break;
            }
        }
        return ans;
    }
};