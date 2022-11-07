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
    void helper(TreeNode* root, vector<int>& ans)
    {
        if(root==NULL){
            ans.push_back(-1);
            return;
        }
        //LNR
        ans.push_back(root->val);
        helper(root->left, ans);
        helper(root->right, ans);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> ans;
        vector<int> ans2;
        
        helper(p,ans);
        helper(q,ans2);
        if(ans.size()!=ans2.size())
            return false;
        for(int i=0; i<ans.size(); i++){
            if(ans[i] != ans2[i])
                return false;
        }
        return true;
    }
};