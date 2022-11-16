class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<int> ans, store;
        for(auto i: nums)
            mp[i]+=1;
        for(auto i: mp){
            store.push_back(i.second);
        }
        sort(store.begin(), store.end(), greater<int>());
        int j=0,count=0;
        unordered_set<int> st;
        for(int i=0; i<store.size() && count<k; i++)
        {
            for(auto it: mp)
            {
                if(it.second==store[i]){
                    int n=st.size();
                    st.insert(it.first);
                    if(st.size()!=n)
                    count++;
                }
                    
            }
        }
        for(auto i: st)
            ans.push_back(i);
        return ans;
    }
};