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
    int length(ListNode* head){
        int cnt=0;
        while(head!=NULL){
            head=head->next;
            cnt++;
        }
        return cnt;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* front=head;
        ListNode* back=head;
        int len=length(head);
        int n=len-k+1;
        while(k>1){
            front=front->next;
            k--;
        }
        while(n>1){
            back=back->next;
            n--;
        }
        swap(front->val,back->val);
        return head;
    }
};