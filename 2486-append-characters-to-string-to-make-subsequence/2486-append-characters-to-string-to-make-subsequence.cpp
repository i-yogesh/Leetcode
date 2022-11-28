class Solution {
public:
    int appendCharacters(string s, string t) {
        
        int i=0,j=0,n=s.length(),m=t.length();
        while(i<n && j<m)
        {
            if(s[i] == t[j]){
                j++;
            }
            i++;
        }
        return t.size()-j;
    }
};