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
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair<TreeNode*, int>> q;
        long maxi  = 0;
        q.push({root, 0});
        while(!q.empty())
        {
            
            int size = q.size();
            int start = q.front().second;
            int end = q.back().second;
            long width = end-start+1;
            maxi = max(maxi, width);
            for(int i=0; i<size; i++)
            {
                pair<TreeNode*,int> p = q.front();
                TreeNode* node = p.first;
                long index = p.second;
                q.pop();
                if(node->left)
                    q.push({node->left, 2*index+1});
                if(node->right)
                    q.push({node->right, 2*index+2});
            }
        }
        return maxi;
    }
};