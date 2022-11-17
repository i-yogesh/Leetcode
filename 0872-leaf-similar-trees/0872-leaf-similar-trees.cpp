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
     void inorder(TreeNode* root,vector<int> &ans)
    {
        //LNR
        if(root == NULL)
            return;
         
        if(!root->left && !root->right)
            ans.push_back(root->val);
        inorder(root->left,ans);
        inorder(root->right,ans);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> arr, arr2;
        inorder(root1, arr);
        inorder(root2, arr2);
        return arr==arr2;
    }
};