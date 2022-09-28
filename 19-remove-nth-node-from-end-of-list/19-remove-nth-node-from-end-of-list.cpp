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
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* forward=NULL;
        while(curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || head->next==NULL && n==1){
            return NULL;
        }
      
        head=reverse(head);
        ListNode* curr=head;
        ListNode* prev=NULL;
        if(n==1){
            curr=curr->next;
            return reverse(curr);
        }
        int cnt=1;
        while(curr!=NULL && cnt<n){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        prev->next=curr->next;
        return reverse(head);
        return head;
    }
};