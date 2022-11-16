class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for(auto i: nums)
            mp[i]+=1;
        vector<vector<int>> bucket(nums.size() , vector<int>());
        for(auto it: mp){
            bucket[it.second-1].push_back(it.first);
        }
        
        for(int i=bucket.size()-1; i>=0 && k>0; i--)
        {
            for(int val: bucket[i]){
                ans.push_back(val);
                k--;
            }
        }
        return ans;
    }
};