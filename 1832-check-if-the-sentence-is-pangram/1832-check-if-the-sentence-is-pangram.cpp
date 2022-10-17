class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<int> st;
        for(auto i: sentence){
            st.insert(i);
        }
        if(st.size() == 26)
            return true;
        else
            return false;
    }
};