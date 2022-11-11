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
            ListNode* ans = new ListNode;
            ans->next=head;
            int sum=0;
            for(ListNode* i = ans; i!=NULL; i=i->next)
            {
                sum=0;
                for(ListNode* j = i->next; j!=NULL; j= j->next)
                {
                    sum+=j->val;
                    if(sum==0)
                        i->next=j->next;
                }
            }
            return ans->next;
        }
};