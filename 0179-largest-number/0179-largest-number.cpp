class Solution {
public:
    static bool cmp(string a, string b){
        return a+b > b+a;
    }
    string largestNumber(vector<int>& nums) {
        string ans="";
        vector<string> store;
        
        for(int i=0; i<nums.size(); i++)
            store.push_back(to_string(nums[i]));
        
        sort(store.begin(), store.end(), cmp);
        for(auto i: store)
            ans+=i;
        if(ans.size() >= 1 && ans[0] == '0')
            return "0";
        return ans;
    }
};