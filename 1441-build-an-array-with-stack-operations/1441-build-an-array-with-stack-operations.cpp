class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<int> store;
        vector<string> ans;
        
        for(int i=1; i<=n; i++)
        {
            ans.push_back("Push");
            store.push_back(i);
            if(find(target.begin(), target.end(), i) == target.end()){
                ans.push_back("Pop");
                store.pop_back();   
            }
            if(store == target)
                break;
        }
        return ans;
    }
};