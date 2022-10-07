/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *swap(ListNode *head)
    {
        if (head == NULL)
            return head;
        ListNode *curr = head;
        ListNode *prev = NULL, *forward = NULL;
        int count = 0;
        while (curr != NULL && count < 2)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            count++;
        }
        head->next = swap(forward);
        return prev;
    }
    ListNode *swapPairs(ListNode *head)
    {
        head = swap(head);
        return head;
    }
};