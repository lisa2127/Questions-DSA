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
    ListNode* reverse(ListNode* head){
        if(head==NULL ||head->next==NULL){
            return head;
        }
        ListNode* prev=NULL;
        ListNode* forward=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(head==NULL|| head->next==NULL){
            return;
        }
        ListNode* curr=head;
        while(curr->next!=NULL){
            curr->next=reverse(curr->next);
            curr=curr->next;
        }
    }
};