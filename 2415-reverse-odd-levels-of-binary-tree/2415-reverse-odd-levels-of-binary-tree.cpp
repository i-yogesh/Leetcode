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
    TreeNode* reverseOddLevels(TreeNode* root) {
        
        if(root == nullptr)
            return nullptr;
        
        int lvl = 0;
        queue<TreeNode*> q;
        q.push(root);
        
        TreeNode* temp = NULL;
        vector<int> arr;
        while(!q.empty())
        {
            int size = q.size();
            vector<int> values;
            for(int i=0; i<size; i++)
            {
                temp = q.front();
                q.pop();
                
                if(lvl%2 != 0)
                    temp->val = arr[size-i-1];
                
                if(temp->left!=NULL){
                    q.push(temp->left);
                    values.push_back(temp->left->val);
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                    values.push_back(temp->right->val);
                }
            }
            
            arr=values;
            lvl++;
        }
        return root;
    }
};