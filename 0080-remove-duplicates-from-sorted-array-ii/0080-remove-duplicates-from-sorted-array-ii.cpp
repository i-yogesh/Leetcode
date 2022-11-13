class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        unordered_map<int, int> mp;
        vector<int> ans;
        int n=0;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(mp.find(nums[i]) != mp.end())
            {
                auto it = mp.find(nums[i]);
                if(it->second==1){
                    ans.push_back(nums[i]);
                    n++;
                    mp[nums[i]]++;
                }
                    
            }
            else{
                mp[nums[i]]++;
                ans.push_back(nums[i]);
                n++;
            }
                
        }
        // for(auto i: ans)
        //     cout<<i<<" ";
        for(int i=0 ;i<ans.size(); i++)
            nums[i]=ans[i];
        return n;
    }
};