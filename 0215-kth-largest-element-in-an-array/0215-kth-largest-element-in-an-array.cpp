class Solution {
public:
    
    int quickSelect(int l, int r, vector<int>& nums,int k)
    {
        int pivot = nums[r];
        int p = l;
        for(int i=l; i<r; i++)
        {
            if(nums[i] <= pivot){
                swap(nums[i], nums[p]);
                p++;
            }
        }
        swap(nums[r], nums[p]);
        if(k<p)
            return quickSelect(l, p-1,nums,k);
        else if(k>p)
            return quickSelect(p+1, r,nums,k);
        else
            return nums[p];
    }
    int findKthLargest(vector<int>& nums, int k) {
        
        k=nums.size()-k;
        return quickSelect(0, nums.size()-1,nums,k);
    }
};