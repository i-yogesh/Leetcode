class Solution {
public:
    bool checkOnesSegment(string s) {
        bool ans=true;
        if(s.size() == 1)
            return true;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == '0' && s[i+1] == '1'){
                ans=false;
                break;
            }
        }
        return ans;
    }
};