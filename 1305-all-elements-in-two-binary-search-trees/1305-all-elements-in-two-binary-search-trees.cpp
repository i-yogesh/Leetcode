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
    void preorder(TreeNode* root, vector<int> &arr)
    {
        if(!root) return;
        preorder(root->left, arr);
        arr.push_back(root->val);
        preorder(root->right,arr);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> arr,arr2, arr3;
        preorder(root1, arr);
        preorder(root2, arr2);
        
        arr3.reserve(arr.size() + arr2.size());
        arr3.insert(arr3.end(), arr.begin(), arr.end());
        arr3.insert(arr3.end(), arr2.begin(), arr2.end());
        sort(arr3.begin(), arr3.end());
        return arr3;
    }
};