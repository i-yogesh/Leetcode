/**
 *Definition for singly-linked list.
 *struct ListNode {
 *   int val;
 *   ListNode * next;
 *   ListNode() : val(0), next(nullptr) {}
 *   ListNode(int x) : val(x), next(nullptr) {}
 *   ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
    ListNode* reverse(ListNode *head)
    {
        ListNode* curr = head, *prev = NULL, *forward = NULL;
        while(curr){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }        
    
    void reorderList(ListNode *head)
    {
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *head2 = slow->next;
        slow->next=NULL;
        
        head2 = reverse(head2);
        
        while(head2)
        {
            ListNode* p1 = head->next;
            ListNode* p2 = head2->next;
            head->next = head2;
            head2->next = p1;
            head = p1;
            head2 = p2;
        }
    }
};