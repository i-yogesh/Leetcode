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
    
    TreeNode* solve(vector<int> &in, vector<int> &post,int &index, int inStart, int inEnd,int n, unordered_map<int, int> &mp)
    {
        if(index<0 || inStart > inEnd)
            return NULL;
        
        int element = post[index--];
        TreeNode* root = new TreeNode(element);
        int pos = mp[element];
        
        root->right= solve(in, post, index, pos+1, inEnd, n, mp);
        root->left = solve(in, post, index, inStart, pos-1, n, mp);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        int postIndex = n-1;
        unordered_map<int, int> mp;
        
        for(int i=0; i<n; i++)
            mp[inorder[i]]=i;
        
        TreeNode* ans = solve(inorder, postorder, postIndex,0, n-1,n,mp);
        return ans;
    }
};