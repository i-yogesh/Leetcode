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
    vector<string> ans;
    
    void solve(TreeNode* root, string s, TreeNode* rootStore)
    {
        if(!root)
            return;
        
        if(root == rootStore)
            s=to_string(root->val);
        else
            s=s+"->"+to_string(root->val);
        if(!root->left && !root->right){
            ans.push_back(s);
            return;
        }
        solve(root->left, s,rootStore);
        solve(root->right, s, rootStore);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        string s;
        solve(root, s, root);
        return ans;
    }
};