/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* removeZeroSumSublists(ListNode *head)
        {
            vector<int> nums;
            ListNode *temp = head;
            while (temp != NULL)
            {
                nums.push_back(temp->val);
                temp = temp->next;
            }

            int sum = 0,i,j;
            for (i = 0; i < nums.size(); i++)
            {
                sum = 0;
                for (j = i; j < nums.size(); j++)
                {
                    sum += nums[j];
                    if (sum == 0)
                        break;
                }
                if (sum == 0)
                {
                    nums.erase(nums.begin() + i, nums.begin() + j + 1);
                    i--;
                }
            }
            if(nums.size() == 0)
                return NULL;
            
            temp = new ListNode(nums[0]);
            ListNode* ans = temp;
            for(int i=1; i<nums.size(); i++)
            {
                ListNode* newN = new ListNode(nums[i]);
                temp->next = newN;
                temp=newN;
            }
            return ans;
        }
};