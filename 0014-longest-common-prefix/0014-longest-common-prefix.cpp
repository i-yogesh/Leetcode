class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
            return "";
        sort(strs.begin(),strs.end());
        string first = strs[0];
        string second = strs[strs.size()-1];
        string ans="";
        for(int i=0; i<second.size();i++)
        {
            if(first[i]==second[i]){
                ans+=first[i];
            }
            else
                break;
        }
        return ans;
    }
};