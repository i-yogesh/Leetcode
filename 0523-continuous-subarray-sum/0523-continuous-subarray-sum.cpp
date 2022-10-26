class Solution {
public:
    int sum=0;
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++)
        {
            sum+=nums[i]; 
            int remainder=sum%k;
            if(remainder==0 && i!=0){
                return true;
            }
            if(mp.find(remainder) != mp.end()){
                if(i-mp[remainder] > 1)
                    return true;
            }
            else
                mp[remainder] = i;
        }
        return false;
    }
};