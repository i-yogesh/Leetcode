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
    
    unordered_map<int, int> mp;
    int preIndex = 0;
    TreeNode* construct(vector<int>& preorder, vector<int>& postorder, int start, int end)
    {
        if(start > end || preIndex >= preorder.size())
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[preIndex]);
        preIndex++;
        
        if(start == end)
            return root;
        
        int pos = mp[preorder[preIndex]];
        root->left = construct(preorder, postorder, start, pos);
        root->right = construct(preorder, postorder, pos+1, end-1);
        
        return root;
    }
    
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        for(int i=0; i<n; i++)
            mp[postorder[i]] = i;
        TreeNode* ans = construct(preorder, postorder, 0, n-1);
        return ans;
    }
};