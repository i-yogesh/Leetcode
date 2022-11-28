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
    TreeNode* solve(TreeNode* root, TreeNode* newN){
        if(root == NULL){
            return newN;
        }
        if(newN->val > root->val){
            root->right = solve(root->right,newN);
        }
        else
            root->left = solve(root->left, newN);
        return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newN = new TreeNode(val);
        root = solve(root, newN);
        return root;
    }
};