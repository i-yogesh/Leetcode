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
    // int lvl = 1;
    void solve(TreeNode* root,int val,int depth, int lvl)
    {
        if(root == NULL)
            return;
        // lvl++;
        if(lvl == depth)
        {
            TreeNode* ll = root->left;
            TreeNode* rr = root->right;
            TreeNode* newL = new TreeNode(val);
            TreeNode* newR = new TreeNode(val);
            root->left = newL;  root->right = newR;
            newL->left = ll; newL->right = NULL;
            newR->right = rr; newR->left = NULL;
            // return;
        }
        solve(root->left, val, depth, lvl+1);
        solve(root->right, val, depth, lvl+1);
        
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(depth == 1)
        {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->right = NULL;
            newRoot->left = root;
            return newRoot;
        }
        int lvl = 1;
        solve(root, val, depth, lvl+1);
        
        return root;
    }
};