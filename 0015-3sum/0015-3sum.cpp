class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        if(nums.size()<3)
            return {};
        if(nums[0]>0)
            return {};
        
        for(int i=0 ;i<nums.size(); i++)
        {
            if(nums[i]>0)
                break;
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            int low=i+1, high=nums.size()-1,sum=0;
            while(low < high)
            {
                sum=nums[low]+nums[high]+nums[i];
                if(sum > 0)
                    high--;
                else if(sum < 0)
                    low++;
                else
                {
                    ans.push_back({nums[i], nums[low], nums[high]});
                    int last_low=nums[low],last_high=nums[high];
                    while(low<high && nums[low] == last_low)
                        low++;
                    while(low<high && nums[high] == last_high)
                        high--;
                }
            }
        }
        return ans;
    }
};  