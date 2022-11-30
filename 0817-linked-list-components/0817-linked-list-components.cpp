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
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        
        ListNode* temp = head;
        int count=0;
        bool connected=false;
        while(temp!=NULL)
        {
            int key = temp->val;
            if(find(nums.begin(), nums.end(), key)!=nums.end())
                connected = true;
            else{
                if(connected)
                count++;
                
                connected=false;
            }
            temp=temp->next;
        }
        if(connected)
            count++;
        
        return count;
    }
};