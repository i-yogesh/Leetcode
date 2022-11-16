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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, map<int, multiset<int> > > mp;
        queue< pair<TreeNode*, pair<int, int>>> q;
        
        q.push(make_pair(root, make_pair(0,0)));
        while(!q.empty())
        {
            pair<TreeNode*, pair<int, int>> p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int hd = p.second.first;
            int lvl = p.second.second;
            // cout<<node->val<<endl;
            mp[hd][lvl].insert(node->val);
            if(node->left)
                q.push(make_pair(node->left, make_pair(hd-1, lvl+1)));
            if(node->right)
                q.push(make_pair(node->right, make_pair(hd+1, lvl+1)));
        }
        
        for(auto i: mp)
        {
            vector<int> store;
            for(auto j: i.second)
                store.insert(store.end(), j.second.begin(), j.second.end());
            ans.push_back(store);
        }
        return ans;
    }
};