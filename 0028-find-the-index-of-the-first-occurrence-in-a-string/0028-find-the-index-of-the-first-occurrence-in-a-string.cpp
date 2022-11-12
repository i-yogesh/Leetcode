class Solution {
public:
    int strStr(string haystack, string needle) {
        string s="";
        int i=0,j=1;
        char ch;
        i=0;
        for(int i=0; i<haystack.size(); )
        {
            s = haystack.substr(i, j-i);
            if(s==needle)
                return i;
            else if(j==haystack.size()){
                i++;
                j=i;
            }
            else
                j++;
        }
        return -1;
    }
};