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
        vector<int> postorderTraversal(TreeNode *root)
        {
            vector<int> ans;
            stack<TreeNode*> st;
            TreeNode *curr = root,*temp=NULL;
            while (curr || !st.empty())
            {
                while (curr)
                {
                    st.push(curr);
                    curr = curr->left;
                }
                temp=st.top()->right;
                if(temp==NULL)
                {
                    temp=st.top();
                    st.pop();
                    ans.push_back(temp->val);
                    while(!st.empty() && temp == st.top()->right){
                        temp=st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                }
                else
                    curr=temp;
            }
            return ans;
        }
};