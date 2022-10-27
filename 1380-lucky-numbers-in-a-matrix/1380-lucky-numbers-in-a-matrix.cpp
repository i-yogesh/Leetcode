class Solution {
public:
    
    int minimum(vector<int> nums, int &index)
    {
        int mini=INT_MAX;
        for(int i=0;i<nums.size(); i++){
            if(nums[i] < mini){
                mini=nums[i];
                index=i;
            }
        }
        return mini;
    }
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;
        for(int i=0; i<matrix.size(); i++)
        {
            int index;
            int mini = minimum(matrix[i], index);
            int maxi=INT_MIN;
            for(int j=0; j<matrix.size(); j++)
            {
                maxi = max(maxi, matrix[j][index]);
            }
            
            if(mini == maxi)
            ans.push_back(maxi);
        }
        return ans;
    }
};