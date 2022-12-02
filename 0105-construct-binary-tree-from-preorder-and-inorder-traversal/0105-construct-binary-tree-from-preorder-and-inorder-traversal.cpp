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
    TreeNode* solve(vector<int> pre, vector<int> in, int &index, int inStart, int inEnd, int n, unordered_map<int, int> &mp)
    {
        if(index>=n || inStart>inEnd)
            return NULL;
        
        int element = pre[index++];
        TreeNode* root = new TreeNode(element);
        int pos = mp[element];
        root->left = solve(pre,in,index, inStart, pos-1, n, mp);
        root->right = solve(pre,in,index,pos+1,inEnd,n,mp);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex = 0, n= inorder.size();
        unordered_map<int, int> mp;
        for(int i=0; i<inorder.size(); i++)
            mp[inorder[i]]=i;
        
        TreeNode* ans = solve(preorder, inorder, preIndex, 0, n-1, n, mp);
        return ans;
    }
};