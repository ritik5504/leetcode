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
    void solve(ListNode* &head,ListNode* curr,ListNode* pre){
        if(curr==nullptr){
            head=pre;
            return;
        }
        ListNode* forw=curr->next;
        solve(head,forw,curr);
        curr->next=pre;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* curr=head;
        ListNode* pre=nullptr;

        solve(head,curr,pre);
        return head;

        
    }
};