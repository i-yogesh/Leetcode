class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto i: arr)
            mp[i]+=1;
        int ans=INT_MIN,maxi=INT_MIN;
        for(auto &it : mp)
        {
            if(it.second>maxi){
                maxi=it.second;
                ans=it.first;
            }
        }
        return ans;
    }
};