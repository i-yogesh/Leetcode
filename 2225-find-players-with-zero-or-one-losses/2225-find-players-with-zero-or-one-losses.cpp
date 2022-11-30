// for(int j=0 ; j<matches[i].size(); j++){
//                 if(matches)
//             }
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> mp_lost, mp_won;
        for(int i=0; i<matches.size(); i++)
        {
            int num = matches[i][1];
            mp_lost[num]++;
        }
        
        for(int i=0; i<matches.size(); i++)
        {
            int num = matches[i][0];
            if(mp_lost.count(num) == 0)
                mp_won[num]++;
        }
        vector<vector<int>> ans(2);
        for(auto i: mp_won){
            ans[0].push_back(i.first);
        }
        for(auto i: mp_lost){
            if(i.second==1)
            ans[1].push_back(i.first);
        }
        
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        return ans;
    }
};