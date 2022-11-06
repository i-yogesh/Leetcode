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
    int helper(TreeNode* root, bool& ans)
    {
        if(root==NULL)
            return 0;
        int left = helper(root->left,ans);
        int right = helper(root->right,ans);
        int res = abs(left-right);
        if(res>1)
            ans=false;
        int maxi =max(left,right)+1;
        return maxi; 
    }
    
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        helper(root,ans);
        return ans;
    }
};