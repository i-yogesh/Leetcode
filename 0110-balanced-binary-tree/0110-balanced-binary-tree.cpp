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
    int helper(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int left = helper(root->left);
        if(left == -1)
            return -1;
        int right = helper(root->right);
        if(right==-1)
            return -1;
        int ans = abs(left-right);
        if(ans>1)
            return -1;
        int maxi =max(left,right)+1;
        return maxi; 
    }
    
    bool isBalanced(TreeNode* root) {
        return helper(root)!=-1;  
    }
};