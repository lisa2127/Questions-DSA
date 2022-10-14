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
        ListNode* forward=NULL;
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* second=reverse(slow->next);
        int ans=INT_MIN;
        while(second!=NULL){
            int sum=head->val+second->val;
            ans=max(ans,sum);
            head=head->next;
            second=second->next;
        }
        return ans;
    }
};