class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for(auto i: nums)
            mp[i]+=1;
        for(auto i: mp){
            if(i.second == 2)
                ans.push_back(i.first);
        }
        return ans;
    }
};