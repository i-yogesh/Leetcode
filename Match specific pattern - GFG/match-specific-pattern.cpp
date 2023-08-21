//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<string> findMatchedWords(vector<string> dict,string pattern);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> s(n);
		for(int i=0;i<n;i++)
		    cin>>s[i];
		
		string tt;
		cin>>tt;
		
		vector<string> res = findMatchedWords(s,tt);
        sort(res.begin(),res.end());
		for(int i=0;i<res.size();i++)
		    cout<<res[i]<<" ";
		cout<<endl;
		
	}
}
// } Driver Code Ends


vector<string> findMatchedWords(vector<string> dict,string pattern)
{
    vector<string> ans;
      for(auto i: dict){
          string curr = i;
          if(curr.size() == pattern.size()){
              int j=0,f=1;
              unordered_map<char,int> mp,mp2;
              while(j<curr.size()){
                  mp[curr[j]]++;
                  mp2[pattern[j]]++;
                  if(mp[curr[j]] !=  mp2[pattern[j]])
                    f=0;
                j++;
              }
              if(f==1)
                ans.push_back(curr);
          }
      }
      return ans;
}