class Solution {
public:
    string breakPalindrome(string palindrome) {
        if(palindrome.size() == 1)
            return "";
        string temp = palindrome;
        char ch='#';
        for(int i=0; i<palindrome.length()/2; i++)
        {
            if(palindrome[i]!='a'){
                ch=i;
                break;
            }
                
        }
        
        if(ch=='#')
            palindrome[palindrome.size()-1]='b';
        else
        palindrome[ch] = 'a';
        return palindrome;
    }
};