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
    void helper(TreeNode* root, int &c){
        if(!root)
            return;
        //LNR
        helper(root->left, c);
        c++;
        helper(root->right, c);
    }
    int countNodes(TreeNode* root) {
        int sum=0;
        helper(root, sum);
        return sum;
    }
};