class Solution {
public:
    static bool cmp(pair<int, char> a, pair<int, char> b){
        return a.first>b.first;
    }
    string frequencySort(string s) {
        string ans="";
        unordered_map<char, int> mp;
        for(auto i: s)
            mp[i]+=1;
        
        vector<pair<int,char>> pr;
        for(auto i: mp)
            pr.push_back({i.second, i.first});
        sort(pr.begin(), pr.end(), cmp);
        for(auto i: pr){
            for(int j=0; j<i.first; j++)
                ans.push_back(i.second);
        }
            
        return ans;
    }
};