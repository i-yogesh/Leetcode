class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        int maxi=num;
        for(int i=0; i<s.size(); i++)
        {
            string ss = s;
            if(s[i] == '6')
            {
                s[i]='9';
                break;   
            }
            
        }
        return stoi(s);
        // if(s[i] == '9')
        //         s[i]='6';
        //     else if(s[i]=='6')
        //         s[i]='9';
        //     int n1 = stoi(s);
        //     int n2 = stoi(ss);
        //     maxi=max(n1, n2);
        //     s=ss;
    }
};