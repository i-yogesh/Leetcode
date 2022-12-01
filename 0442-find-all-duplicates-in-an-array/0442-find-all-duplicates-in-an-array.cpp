class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int i=0;
        vector<int> ans;
        for(; i<nums.size();i++)
        {
            
            int val = abs(nums[i]);
            int index = val - 1;
            if(nums[index] < 0)
                ans.push_back(index+1);
            else
                nums[index] *= -1; 
        }
        return ans;
    }
};