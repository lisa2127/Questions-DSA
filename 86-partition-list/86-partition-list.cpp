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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* curr=head;
        ListNode* h1=new ListNode(-1);
        ListNode* head1=h1;
        ListNode* h2=new ListNode(-1);
        ListNode* head2=h2;
        while(curr!=NULL){
            if(curr->val<x){
               head1->next=curr;
               head1=curr;
            }
            else{
                 head2->next=curr;
                 head2=curr;
            }  
            curr=curr->next;
        }
 
        head2->next=NULL;
        head1->next=h2->next;
        return h1->next;
    }
};