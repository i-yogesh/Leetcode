class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<char> st;
        char ans;
        for(int i=0; i<s.length(); i++)
        {
            if(st.find(s[i]) != st.end()){
                ans=s[i];
                break;
            }
                // return s[i];
            st.insert(s[i]);
        }
        return ans;
    }
};