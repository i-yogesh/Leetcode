/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<string> arr;
    void solve(TreeNode* root, string s)
    {
        if(root==NULL)
            return;
        int num = root->val;
        char ch = (char)num; ch = ch+'a';
        s = s + (ch);
        
        if(root->left==NULL && root->right==NULL){
            arr.push_back(s);
        }
        solve(root->left, s);
        solve(root->right, s);
    }
    string smallestFromLeaf(TreeNode* root) {
        string s="", ans="";
        solve(root, s);
        for(int i=0; i<arr.size(); i++)
        {
            string ss = arr[i];
            reverse(ss.begin(), ss.end());
            arr[i] = ss;
        }
        sort(arr.begin(), arr.end());
        // for(auto i: arr)
        //     cout<<i<<" ";
        return arr[0];
    }
};