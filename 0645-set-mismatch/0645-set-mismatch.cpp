class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        map<int, int> mp;
        for(int i=0; i<nums.size(); i++)
            mp[nums[i]]++;
        for(auto &i: mp){
            if(i.second>1){
                ans.push_back(i.first);
                break;
            }
        }
        for(int i=1 ;i <= nums.size()+1; i++){
            if(mp[i]==0){
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};