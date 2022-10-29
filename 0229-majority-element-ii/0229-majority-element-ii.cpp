class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++)
        {
            mp[nums[i]]+=1;
        }
        
        int n3 = nums.size()/3;
        
        for(auto it: mp)
        {
            if(it.second > n3)
                ans.push_back(it.first);
        }
        return ans;
    }
};