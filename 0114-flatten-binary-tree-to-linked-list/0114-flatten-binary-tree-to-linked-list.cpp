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
    void preorder(TreeNode* root, vector<TreeNode*> &ans)
    {
        if(!root)
            return;
        //NLR
        ans.push_back(root);
        preorder(root->left,ans);
        preorder(root->right, ans);
    }
    
    void flatten(TreeNode* root) {
        if((root==NULL ) || (!root->left && !root->right)) return;
        
        vector<TreeNode*> arr;
        preorder(root, arr);
        TreeNode* temp = root;
        
        for(int i=0; i<arr.size(); i++){
            temp->left = NULL;
            temp->right = arr[i];
            temp=temp->right;
        }
    }
};