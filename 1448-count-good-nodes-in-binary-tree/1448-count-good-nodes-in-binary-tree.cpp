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
    int count = 0;
    
    void solve(TreeNode* root, int maxi, TreeNode* ptr)
    {
        if(root==NULL)
            return;
        if(maxi <= root->val)
            count++;
        if(ptr == root && count!=0){
            maxi = ptr->val;
        }
        else
        maxi = max(root->val, maxi);
        
        solve(root->left, maxi, ptr);
        solve(root->right, maxi, ptr);
    }
    
    int goodNodes(TreeNode* root) {
        int maxi=root->val;
        
        if(root==NULL)
            return count;
        
        TreeNode* ptr = root;
        solve(root, maxi, ptr);
        return count;
    }
};