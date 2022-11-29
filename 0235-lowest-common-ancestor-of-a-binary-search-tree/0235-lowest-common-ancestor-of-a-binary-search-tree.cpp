/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool solve(TreeNode* root, TreeNode* key, vector<TreeNode*> &arr){
        if(!root)
            return false;
        
        arr.push_back(root);
        if(root == key)
            return true;
        if(solve(root->left,key, arr) || solve(root->right,key, arr))
            return true;
        arr.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> arr1, arr2;
        solve(root,p,arr1);
        solve(root,q, arr2);
        TreeNode* ans=arr1[0];
        for(int i=0; i<arr1.size() && i<arr2.size(); i++){
            if(arr1[i] != arr2[i])
                return ans;
            ans=arr1[i];
        }
        return ans;
    }
};