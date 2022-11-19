class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        
        string ans="";
        map<string, int> mp;
        for(int i=0; i<messages.size(); i++)
        {
            string s = messages[i];
            int c=0;
            for(int j=0; j<s.size(); j++){
                char ch = s[j];
                if(isspace(ch)){
                    c=1;
                    mp[senders[i]]+=1;
                }
            }
            mp[senders[i]]+=1;
        }
        
        int maxi = INT_MIN;
        for(auto i: mp){
            if(i.second >= maxi){
                maxi=i.second;
                if(i.first>ans)
                    ans=i.first;
            }
        }
        return ans;
    }
};