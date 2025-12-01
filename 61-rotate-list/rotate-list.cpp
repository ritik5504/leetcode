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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0)return head;
        ListNode* tail=head;
        int n=1;
        while(tail->next){
            tail=tail->next;
            n++;
        }
        k%=n;
        if(k==0)return head;

        tail->next=head;

        int step=n-k-1;
        ListNode* newtail=head;
        for(int i=0;i<step;i++){
            newtail=newtail->next;

        }
        ListNode* newhead=newtail->next;

        newtail->next=nullptr;

        return newhead;
       
       


        
    }
};