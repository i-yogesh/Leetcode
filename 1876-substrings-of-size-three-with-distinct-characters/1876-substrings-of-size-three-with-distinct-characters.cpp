class Solution {
public:
    int countGoodSubstrings(string s) {
        if(s.length()<3)
            return 0;
        int count = 0;
        string arr;
        for(int i=0; i<3; i++)
            arr.push_back(s[i]);
        int j=0;
        if(arr[0]==arr[1] || arr[0]==arr[2] || arr[1]==arr[2])
            j=0;
        else
            count++;
 
        for(int i=3; i<s.length(); i++)
        {
            arr.erase(0,1);
            arr.push_back(s[i]);
            if(arr[0]==arr[1] || arr[0]==arr[2] || arr[1]==arr[2])
                j=0;
            else
                count++;
        }
        return count;
    }
};