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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> arr;
        q.push(root);
        while(!q.empty())
        {
            int len = q.size();
            arr.clear();
            while(len--)
            {
                TreeNode* node = q.front();
                
                if(node)
                {
                    arr.push_back(node->val);
                    if(node->left)
                    q.push(node->left);
                    if(node->right)
                    q.push(node->right);
                }
                q.pop();
            }
        }
        return arr[0];
    }
};