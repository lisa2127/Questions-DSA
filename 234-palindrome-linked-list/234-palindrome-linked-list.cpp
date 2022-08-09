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
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return true;
        }
        stack<int> s;
        ListNode* temp=head;
        ListNode* curr=head;
        while(curr!=NULL){
            s.push(curr->val);
            curr=curr->next;
        }
        while(temp!=NULL){
            if(temp->val!=s.top()){
                return false;
            }
            s.pop();
            temp=temp->next;
        }
        return true;
        
    }
};