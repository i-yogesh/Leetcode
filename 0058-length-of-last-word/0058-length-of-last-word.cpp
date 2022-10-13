class Solution {
public:
    int lengthOfLastWord(string s) {
        int count=0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == ' ' && i+1<s.length() && s[i+1]!=' '){
                count=0;
            }
            else if(s[i]!=' ')
            count++;
        }
        return count;
    }
};