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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==nullptr|| head->next==nullptr)return nullptr;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* pre=slow;

        while(fast != nullptr && fast->next != nullptr){
            pre=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        pre->next=slow->next;
        delete slow;

        return head;
        
    }
};