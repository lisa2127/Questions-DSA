/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* solve(ListNode* head){
       ListNode* fast=head;
       ListNode* slow=head;
        while(fast!=NULL && fast->next!=NULL){
           fast=fast->next->next;
           slow=slow->next;
           if(fast==slow){
               return slow;
               break;
           }
       }
        return NULL;
    }
    ListNode *detectCycle(ListNode *head) {
       if(head==NULL || head->next==NULL){
           return NULL;
       }
        ListNode* f=head;
        ListNode* s=solve(head);
       if(s!=NULL){
          while(f!=s){
              f=f->next;
              s=s->next;
          } 
       }
        return s;
    }
};