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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int len = q.size();
            vector<int> store;
            while(len--)
            {
                TreeNode* node = q.front();
                
                if(node)
                {
                    store.push_back(node->val);
                    if(node->left)
                    q.push(node->left);
                    if(node->right)
                    q.push(node->right);
                }
                q.pop();
            }
            ans.push_back(store[store.size()-1]);
        }
        return ans;
    }
};