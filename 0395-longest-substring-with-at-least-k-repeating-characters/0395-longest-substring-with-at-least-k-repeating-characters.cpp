class Solution {
public:
    int longestSub(int start, int end, string &s, int k)
    {
        //empty subtring
        if(start > end)
            return 0;
        //storing frequency
        unordered_map<int,int> mp;
        for(int i=start; i<=end; i++)
            mp[s[i]]+=1;
        
        int breakPoint = -1;
        //getting the breakPoint for creating a new substring
        for(int i=start; i<=end; i++){
            if(mp[s[i]] < k){
                breakPoint = i;
                break;
            }
        }
        //if no character's frequency is less than k return current substring size;
        if(breakPoint == -1)
            return (end-start+1);
        //else divide and conquer
        int left = longestSub(start, breakPoint-1, s, k);
        int right = longestSub(breakPoint+1, end, s, k);
        
        return max(left, right);
    }
    int longestSubstring(string s, int k) {
        
        return longestSub(0, s.size()-1, s, k);
    }
};