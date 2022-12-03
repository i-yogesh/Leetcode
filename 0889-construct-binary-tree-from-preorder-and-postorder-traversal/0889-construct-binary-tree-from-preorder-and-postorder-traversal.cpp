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
    
    TreeNode* solve(vector<int>& pre, vector<int>& post, int preStart, int preEnd, int postStart, int postEnd, unordered_map<int, int> &mp)
    {
        if(preStart > preEnd)
            return NULL;
        
        int element = pre[preStart];
        TreeNode* root = new TreeNode(element);
        if(preStart == preEnd)
            return root;
        
        int postIndex=postStart;
        while(post[postIndex]!=pre[preStart+1])
            postIndex++;
        //postIndex is the breaking point
        int len = postIndex-postStart+1;
        root->left = solve(pre, post, preStart+1, preStart+len, postStart, postIndex, mp);
        root->right = solve(pre, post, preStart+len+1, preEnd, postIndex+1, postEnd-1, mp);
        
        return root;
    }
    
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int preIndex = 0;
        int n = preorder.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++)
            mp[postorder[i]] = i;
        
        TreeNode* ans = solve(preorder, postorder, 0,n-1, 0, n-1, mp);
        return ans;
    }
};