class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        
        
        unordered_set<int> st1,st2,st3;
        for(int i=0; i<nums1.size(); i++)
            st1.insert(nums1[i]);
        
        for(int i=0; i<nums2.size(); i++)
            st2.insert(nums2[i]);
        
        for(int i=0; i<nums3.size(); i++)
            st3.insert(nums3[i]);
        
        unordered_map<int, int> mp;
        for( auto it = st1.begin(); it!=st1.end(); ++it){
            int ans = *it;
            mp[ans]++;
        }
        for( auto it = st2.begin(); it!=st2.end(); ++it){
            int ans = *it;
            mp[ans]++;
        }
        for( auto it = st3.begin(); it!=st3.end(); ++it){
            int ans = *it;
            mp[ans]++;
        }
        
        vector<int> ans;
        for(auto &it: mp)
        {
            if(it.second>=2)
                ans.push_back(it.first);
        }
        return ans; 
    }
};