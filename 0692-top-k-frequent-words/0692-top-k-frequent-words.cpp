class Solution {
public:
    static bool cmp(pair<string, int> a, pair<string, int> b)
    {
        if(a.second == b.second)
            return a.first < b.first;
        return a.second > b.second;        
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(auto i: words)
            mp[i]++;
        
        vector<pair<string, int>> arr(mp.begin(), mp.end());
        // vector<pair<string, int>> arr;
        // for(auto &i: mp)
        //     arr.push_back({i.first, i.second});
        sort(arr.begin(), arr.end(), cmp);
        vector<string> ans;
        
        int i=0;
        while(k--)
            ans.push_back(arr[i++].first);
        
        return ans;
    }
};