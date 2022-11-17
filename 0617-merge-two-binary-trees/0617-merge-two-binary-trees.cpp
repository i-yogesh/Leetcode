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
        void merge(TreeNode *root1, TreeNode *root2, TreeNode* &root)
        {
            if (root1 == NULL && root2 == NULL)
                return;
            
            else if(root1 && !root2){
                TreeNode *newN = new TreeNode();
                newN->val=root1->val;
                root=newN;
                merge(root1->left, root2, root->left);
                merge(root1->right, root2, root->right);
            }
            
            else if(!root1  && root2){
                TreeNode* newN = new TreeNode();
                newN->val+=root2->val;
                root=newN;
                merge(root1, root2->left, root->left);
                merge(root1, root2->right, root->right);
            }
            else if(root1 && root2)
            {
                TreeNode* newN = new TreeNode();
                newN->val = root1->val + root2->val;
                root=newN;
                merge(root1->left, root2->left, root->left);
                merge(root1->right, root2->right, root->right);
            }
        }
    TreeNode* mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        TreeNode *root(nullptr);
        merge(root1, root2, root);
        return root;
    }
};