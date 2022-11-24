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
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &mp)
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                TreeNode* node = q.front();
                q.pop();
                
                if(node!=NULL)
                {
                    if(node->left){
                        mp[node->left]=node;
                        q.push(node->left);
                    }
                    if(node->right){
                        mp[node->right]=node;
                        q.push(node->right);
                    }
                }
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parents;
        markParents(root, parents);
        
        queue<TreeNode*> que;
        que.push(target);
        unordered_map<TreeNode*, bool> visited;
        visited[target]=true;
        
        int count = 0;
        while(!que.empty())
        {
            if(count == k)
                break;
            count++;
            int sz = que.size();
            for(int i=0; i<sz; i++)
            {
                TreeNode* node = que.front();
                que.pop();
                
                if(node->left && !visited[node->left]){
                    que.push(node->left);
                    visited[node]=true;
                }
                if(node->right && !visited[node->right]){
                    que.push(node->right);
                    visited[node]=true;
                }
                if(parents[node] && !visited[parents[node]]){
                    que.push(parents[node]);
                    visited[parents[node]]=true;
                }
            }
        }
        vector<int> ans;
        while(!que.empty())
        {
            int value = que.front()->val;
            ans.push_back(value);
            que.pop();
        }
        return ans;
    }
};