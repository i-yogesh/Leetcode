class Solution {
public:
    string removeSpaces(string str)
    {
        str.erase(remove(str.begin(), str.end(), ' '), str.end());
        return str;
    }
    
    bool isPalindrome(string s) {
        s=removeSpaces(s);
        string ans;
        for(int i=s.length()-1; i >= 0; i--)
        {
            if((s[i] >= 'a' && s[i] <='z') || (s[i] >= 'A' && s[i] <='Z') || (s[i] >='0' && s[i]<= '9'))
            {
                
                ans.push_back((char)tolower(s[i]));
            }
            
        }
        
        string ss = ans;
        reverse(ss.begin(), ss.end());
        
        // cout<<ss<<" "<<ans;
        if(ans == "")
            return true;
        if(ans == ss)
            return true;
        return false;
    }
};