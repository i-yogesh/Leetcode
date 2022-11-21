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
    
    void solve(TreeNode* leftRoot, TreeNode* rightRoot, int lvl)
    {
        if(leftRoot==NULL && rightRoot == NULL)
            return;
        if(lvl%2==0)
            swap(leftRoot->val, rightRoot->val);
        solve(leftRoot->left, rightRoot->right, lvl+1);
        solve(leftRoot->right, rightRoot->left, lvl+1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        int lvl = 0;
        solve(root->left, root->right, lvl);
        return root;
    }
};