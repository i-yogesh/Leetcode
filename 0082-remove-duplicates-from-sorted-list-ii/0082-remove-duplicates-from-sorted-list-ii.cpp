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
    void createMap(ListNode* head, unordered_map<int, int> &mp)
    {
        ListNode* temp = head;
        while(temp!=NULL)
        {
            int data = temp->val;
            mp[data]++;
            temp=temp->next;
        }
    }
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return head;
        
        unordered_map<int, int> mp;
        ListNode* temp = head;
        createMap(head, mp);
        
        vector<int> arr;
        for(auto i: mp){
            if(i.second==1)
                arr.push_back(i.first);
        }
        if(arr.empty())
            return NULL;
        
        sort(arr.begin(), arr.end());
        ListNode* ans = new ListNode(arr[0]);
        ListNode* tail = ans;
        for(int i=1; i<arr.size(); i++){
            ListNode* newN = new ListNode(arr[i]);
            tail->next=newN;
            tail = newN;
        }
        tail->next=NULL;
        return ans;
    }
};