/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        TreeNode* solve(TreeNode *root, int key)
        {
            if (!root) return root;

            if (key < root->val)
                root->left = solve(root->left, key);
            else if (key > root->val)
                root->right = solve(root->right, key);
            else
            {
                if(!root->left && !root->right)
                    return NULL;
                
                    if (root->left && !root->right)
                        return root->left;
                    else if (!root->left && root->right)
                        return root->right;
                   	//Right side me sbse chota, inorder successor
                    if(root->left && root->right){
                        TreeNode* temp = root->right;
                        while(temp->left)
                            temp=temp->left;
                        root->val = temp->val;
                        root->right = solve(root->right, temp->val);
                    }
            }
            return root;
        }
    TreeNode* deleteNode(TreeNode *root, int key)
    {
        if (root == NULL) return root;
        return solve(root, key);
    }
};